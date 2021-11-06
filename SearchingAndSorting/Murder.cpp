
#include<iostream>
using namespace std;
typedef long long ll;
/*
 Total number of greater elements previously seen
 (Inversion Count)
 OR
 for every index find all smaller values that lie ahead
 ie A[i]>A[j]   j>i
 **/
ll merge(ll a[],int left,int mid,int right){
    // mid here is actually starting index of right ie mid+1 for calling array
    ll count=0;
    int i=left;
    int j=mid;
    int lenRight=right+1;// counterpart to mid in right
    ll temp[right-left+1]; int k=0;
    while(i<mid && j<=right){// notice the conditions carefully
        if(a[i]<a[j]){
            count+=((lenRight-j)*a[i]);
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
        }
    }
    while(i<mid){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    // copy temp array to original array [left,right]
    for(int i=left,k=0;i<=right;i++,k++){
        a[i]=temp[k];
    }
    return count;
}
ll merge_sort(ll A[],int left,int right){
    ll count=0;
    if(right>left){
        int mid=(left+ ((right-left)/2));
        ll countLeft=merge_sort(A, left, mid);
        ll countRight=merge_sort(A, mid+1, right);
        ll myCount=merge(A,left,mid+1,right);
        return myCount+countLeft+countRight;
    }
    return count;
}
ll solve(ll A[],int n){
    return merge_sort(A, 0, n-1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
            int n;cin>>n;
            ll* arr=new ll[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
        cout<<solve(arr, n)<<endl;
            
            delete [] arr;
        }    return 0;}

