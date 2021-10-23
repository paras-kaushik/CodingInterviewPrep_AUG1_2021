/*
 
 WE HAVE TO CALCULATE NUMBER OF DIVISORS OF FACTORIAL OF GIVE NUMBER
 
 1                              NAIVE
        calcultae n! and then for i=1 to n!/2 check kar lo kon kon div hai
 2                              LOGIC:
        evry number n can expressed as product of primes ! N=2^a * 3^b* 5^c...
        for any N =p1^a *p2^b *p3^c *p4^d *p5^e *....(pi<=n)
        THE NUMBER OF DIVISORS IS =  (a+1)*(b+1)*(c+1)*(d+1)....(k+1)
        so effectively hume n se chote sare primes ki power chahie
        in the prime factors representation of n
        
        any given prime will occur like p,2p,3p    kp<=n
                    ->> k=n/p +n/(p^2)+n/(p^3)....
 
 
 nloglogn time complexity
 
 */





#include<iostream>
#include<vector>
# define MAX 50001
#define MOD 1000000007
typedef long long ll;
using namespace std;

vector<int>* makeSeive(){
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++){
        isPrime[i]=true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    
    for(int i=2;i*i<MAX;i++){ //if we take care of every factor less than sqrt(n)
        if(isPrime[i]==true){
            for(int j=i*i;j<MAX;j=j+i){
                isPrime[j]=false;
            }
        }
    }
    vector<int>* allPrimes=new vector<int>();
    
    for(int i=2;i<MAX;i++){
        if(isPrime[i]){
            allPrimes->push_back(i);
            // cout<<i<<endl;
        }
    }
    // cout<<allPrimes->at(2);
    
    return allPrimes;
    
    
}
ll findDivisors(int n,vector<int>*& primes){
    
    ll ans=1;
    for(int i=0;primes->at(i)<=n;i++)// all primes less than equal to n
    {
        ll count=0;
        ll k=primes->at(i);
        while((n/k)!=0){
            count=(count+(n/k)%MOD)%MOD;
            k=k*primes->at(i);// k^2 ->> k^3 ->> k^4....
        }
        // cout<<primes->at(i)<<" "<<count+1<<endl;
        ans=(ans*(count+1)%MOD)%MOD;
    }
    
    return ans;
}
int main(){
    // Write your code here
    vector<int>* primes=makeSeive();// precomputation
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=findDivisors(n,primes);
        cout<<ans<<endl;
    }
    return 0;
}

