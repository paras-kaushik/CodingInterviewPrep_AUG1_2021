
#include<iostream>
using namespace std;
void swap(int *arr ,int i,int j,int n){
    if(i<0 || i>=n || j<0 || j>=n){
        return;
    }
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int* arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int flag=1;
        for(int i=0;i<(n-1);i++){
            if(arr[i+1]==arr[i]-1){
                swap(arr,i+1,i,n);
            }
            if(arr[i]!=arr[i+1]-1){flag=0;}
        }
        
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        delete [] arr;
    }
  
    
}
