

#include <iostream>
#include <climits>
# include <algorithm>
#include <utility>
#include <stdio.h>
using namespace std;
struct node{
    int maximum;
    int secmaxmimum;
};

void build(int* arr,node* tree,int st,int l,int r){
    if(l==r){
        tree[st].maximum=arr[l];
        tree[st].secmaxmimum=INT_MIN;
        return;
    }
    int mid=(l+r)/2;
    build(arr, tree, 2* st, l, mid);
    build(arr,tree,2*st+1,mid+1,r);
    
    node left=tree[2*st];
    node right=tree[2*st+1];
    tree[st].maximum=max(left.maximum,right.maximum);
    tree[st].secmaxmimum=min(max(left.secmaxmimum,right.maximum),max(left.maximum,right.secmaxmimum));
}

node query(node* tree,int l,int r,int st,int x,int y){// query for sum of max pair in range
   
    if(l>y || r<x){
        node dummy;
        dummy.maximum=INT_MIN;
        dummy.secmaxmimum=INT_MIN;
        return dummy ;
    }
    if(l>=x && r<=y){
        return tree[st];
    }
    int mid=(l+r)/2;
    node lef=query(tree, l, mid, 2*st, x,y);
    node rit=query(tree, mid+1, r, 2*st+1, x,y);
    
    node ans;
    ans.maximum=max(lef.maximum,rit.maximum);
    ans.secmaxmimum=min(max(lef.secmaxmimum,rit.maximum),max(lef.maximum,rit.secmaxmimum));
    return ans;
}

void updatetree(int* arr,node* tree,int s,int e,int st,int idx,int val){
    
    if(s==e){
        arr[idx]=val;
        tree[st].maximum=val;
        tree[st].secmaxmimum=INT_MIN;
        return;
    }
    int mid=(s+e)/2;
    if(idx>mid){
        updatetree(arr, tree, mid+1, e, 2*st+1, idx, val);
    }else{
        updatetree(arr, tree, s, mid, 2*st, idx, val);
    }
    node left=tree[2*st];
    node right=tree[2*st+1];
    
    tree[st].maximum=max(left.maximum,right.maximum);
    tree[st].secmaxmimum=min(max(left.secmaxmimum,right.maximum),max(left.maximum,right.secmaxmimum)     );
    
}

int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node* tree=new node[3*n];// Actally logically should be 2n(2*N-1)
    //ACTUALLY LOGICLLY SARE ANSWERS 2*N NODES PAR HI HONGE PAR HUME ISSE AGE KE INDEX BHI ACESS KARNE PAD RAHE HAI . SO TO AVOID SEGMENTATION FAULT USE 3*N
    build(arr,tree,1,0,n-1);
    int q;
    cin>>q;
    while(q--){
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='Q'){
            //query
            node ans=query(tree, 0, n-1, 1, l-1, r-1);
            int val=ans.maximum+ans.secmaxmimum;
            cout<<val<<endl;
        }else{
            //update
            updatetree(arr,tree,0,n-1,1,l-1,r);
            
        }
    }
    return 0;
}





