/*
 Segmented Seive
 print all primes from given interval L to U
 [2 <= L < U <= 2147483647]  U is greater than 10^8
 but [U-L <= 1000000]
 
 **/
#include<iostream>
#include<vector>
typedef  long long  ll;
#define MAX 100001// PRECOMPUTING PRIMES FOR 2 TO SQRT(Rmax)
using namespace std;
vector<int>* seive(){
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++){ isPrime[i]=true;}// everything prime
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i){
                isPrime[j]=false;
            }
        }
    }
    vector<int>* primes=new vector<int>();
    primes->push_back(2);
    for(int i=3;i<MAX;i+=2){// ALL PRIMES ARE ODD
        if(isPrime[i]){
            primes->push_back(i);
        }
    }
    return primes;
}
void  printPrimes(ll l,ll r,vector<int>*& primes){
    // the smallest multiple of every prime here -which has to be marked false is (n/p)*p , +p if it becomes /p
    ll n=r-l+1;
    bool isPrime[n];
    for(int i=0;i<(n);i++){
        isPrime[i]=true;
    }
    for(int i=0;primes->at(i)*primes->at(i)<=r;i++){
        int currPrime=primes->at(i);
        // all the multiples of of currPrime IN range are needed
        ll base=((l/currPrime)*currPrime);
        if(base<l){
            base+=currPrime;
        }
        for(ll j=base;j<=r;j+=currPrime){
            isPrime[j-l]=false;
        }
        //edge case
        if(base==currPrime){
            isPrime[base-l]=true;
        }
    }
    for(int i=0;i<n;i++){
        if(isPrime[i]==true){
            cout<<i+l<<endl;
        }
        
    }
    
}

int main(){
    vector<int>* primes=seive();
    int t;
    cin>>t;
    while(t--){
        ll l,r;cin>>l>>r;
        printPrimes(l,r,primes);
    }
    
    return 0;
}
