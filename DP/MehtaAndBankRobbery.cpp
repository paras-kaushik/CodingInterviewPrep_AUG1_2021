
#include<iostream>
#include<algorithm>
#include<utility>
typedef long long ll;
using namespace std;
int main(){
    int n,w;// n items , we have a bag of capacity w units
    cin>>n>>w;
    pair<ll, ll> * arr=new pair<ll, ll>[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;//profit and weight of the ith item
    }
    sort(arr, arr+n);// we want arr[n-1] to be multiplied by highest prime- so that profit becomes max
    // as p value depends only on previous p value -(they are sorted primes)
    
    ll*** dp=new ll**[2];  // dp is 3d
    for(int i=0;i<2;i++){
        dp[i]=new ll*[n+1];//  dp[i] is 2d
        for(int j=0;j<(n+1);j++){
            dp[i][j]=new ll[w+1]; // dp[i][j] is 1d
            for(int k=0;k<w+1;k++){
                dp[i][j][k]=0;
            }
        }
    }
    // dp[10][n][w] would represent the  maximum profit obtainable by using 10 primes with n items having a bag of capacity w units
    int primes[11]={1,2,3,5,7,11,13,17,19,23,29};//He has first 10 primes with him, which he can use atmost once
   
    
    
    // base case is the bottom most 2d array in the 3d stack it has 0 primes - its same as knapsack
    // for n=0 || w=0 profit is zero
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[0][i][j]=dp[0][i-1][j];// leave this item
            if(j>=arr[i-1].second){// item i-> index i-1 can be put in bag -lets try it
                ll include=(arr[i-1].first+dp[0][i-1][j-arr[i-1].second]);
                dp[0][i][j]=max(dp[0][i][j],include);// effectivly max value by inlcluding or excluding
            }
            
        }
    }
    
    
    int p=1;
    for(int prime=1;prime<=10;prime++){
        p=prime%2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){// (n+1)(w+1) 2d slice for every p
                dp[p][i][j]=dp[p][i-1][j];// leave this item
                
                if(j>=arr[i-1].second){// item i-> index i-1 can be put in bag -lets try it
                    
                    ll include=(arr[i-1].first+dp[p][i-1][j-arr[i-1].second]);
                    
                    dp[p][i][j]=max(dp[p][i][j],include);// effectivly max value by inlcluding or excluding
                    
                    ll includeWithPrime=( arr[i-1].first*primes[prime] + dp[p^1][i-1][j-arr[i-1].second]);
                    
                    dp[p][i][j]=max(dp[p][i][j],includeWithPrime);
                }
            }
        }
    }
    
    cout<<dp[p][n][w];
    return 0;
}
