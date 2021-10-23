
#include<iostream>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#include<string>
#include<climits>
#include<vector>
#include<unordered_set>
#include<cmath>
#include<utility>
typedef unsigned long long  ull;
#define MOD 1000000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    int * arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+n);
    // mad-> Maxium Absolute Difference ie difference between the maximum value and minimum value
    int mad_i=arr[n-1]-arr[0];
    int small=arr[0]+k;
    int big=arr[n-1]-k;
    if(small>big){
        swap(big,small);
    }
    int mad_f=(big-small);
    // we will try to maintain our small ans big -as for them we know ans
    for(int i=1;i<(n-1);i++){
        int subtract=arr[i]-k;
        int add=arr[i]+k;
        if(subtract>=small){
            arr[i]=subtract;continue;
        }else if(add<=big){
            arr[i]=add; continue;
        }else{
            // we have got a badass over here ! its +-k disrupt both our min and max and hence our mad_f
            int new_minimum_candidate=subtract;
            int new_maximum_candidae=add;
            int mad_if_we_choose_the_new_min=big-new_minimum_candidate;
            int mad_if_we_choose_the_new_max=add-small;
            
            if(mad_if_we_choose_the_new_min<=mad_if_we_choose_the_new_max){
                small=new_minimum_candidate;
                mad_f=(big-small);
                arr[i]=small;continue;
              
            }else{
                big=new_maximum_candidae;
                mad_f=(big-small);
                arr[i]=big;continue;
            }
        }
    }
    cout<<min(mad_i,mad_f);
    
    return 0;
}
