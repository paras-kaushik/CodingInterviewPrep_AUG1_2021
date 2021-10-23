#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
//                          SEIVE OF ERATOSTHENES
int countPrimes(int n){
    bool* isPrime=new bool[n+1];
    for(int i=0;i<=n;i++){
        isPrime[i]=true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    
    for(int i=2;(i*i)<=n;i++){// finding all multiples below sqrt(n) is eqivalent to finding all above sqrt(n)
        if(isPrime[i]){
        for(int j=i*i;j<=n;j+=i){
            isPrime[j]=false;
        }
        }
    }
    int count=0;
    for(int i=0;i<n+1;i++)
    {   
        if(isPrime[i]==true)
            count++;
    }
    
    return count;
}




int main(){
    int n;
    cin>>n;
    //number of primes in the range [1,N].
    int x=countPrimes(n);
    cout<<x<<endl;
    
    return 0;
}