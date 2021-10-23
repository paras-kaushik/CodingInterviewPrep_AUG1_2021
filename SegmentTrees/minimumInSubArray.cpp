#include <iostream>
#include<climits>
using namespace std;
int arr[100004];
int tree[4*100004];
void build(int l,int r, int st){
    if(l==r){tree[st]=arr[l];return;}
    int mid=((l+r))/2;
    build(l,mid,2*st);
    build(mid+1,r,2*st+1);
    tree[st]=min(tree[2*st],tree[2*st+1]);
}
int query(int l,int r,int x,int y,int st){
    if(l>y || r<x){return INT_MAX;}
    if(l>=x && r<=y){return tree[st];}// the cumulative answer of this full range is needed for final ans
    int mid=((l+r)/2);
    int left_ans=query(l, mid, x, y, 2*st);
    int right_ans=query(mid+1, r, x, y, 2*st+1);
    return min(left_ans,right_ans);
}
void update(int l,int r,int index,int val,int st){
    if(l==r){
        tree[st]=val;
        arr[l]=val;
        return;
    }
    int mid=((l+r)/2);
    int lef=st+st;
    int rit=lef+1;

    if(index>mid){
        update(mid+1, r, index, val,rit);
    }else{
        update(l, mid, index, val,lef);
    }
    
    tree[st]=min(tree[lef],tree[rit]);
}
int main() {
    
    int n,q,a,b;char ch;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(0,n-1,1);
    while (q--) {
        cin>>ch>>a>>b;
        if(ch=='q'){
            cout<<query(0,n-1,a-1,b-1,1)<<endl;// notice we bring asked ranged in accordance with zero based indexing
        }else if(ch=='u'){
            update(0,n-1,a-1,b,1); // arr[a-1]=b
        }
        
    }
    return 0;
}

