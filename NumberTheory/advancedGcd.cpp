
/*
 gcd(a,b) where max(a)==40000 and max(b)== 10^250 ! 

 1     HAVE TO TAKE INPUT IN A GODDAM STRING !
 2     HAVE TO TAKE MODULO OF THAT STRING AND CONERT THAT TO INT FOR OUR GCD FXN

 */
#include <iostream>
#include <string.h>
using namespace std;
int gcd2(int a,int b){
    if(b>a)return gcd2(b,a);
    if(b==0)return a;  
    return gcd2(b, a%b);
}
int main(){    
    int t;cin>>t;
    while(t--){
        int a;
        string b;// given hai ki b hi range ke bahar hai
        cin>>a>>b;
        if(a==0){   cout<<b<<endl; continue;}
        //Assuming a is bigger (and even a string) gcd (a,b)= gcd(b,a%b)
        int num=0;
        int n=b.size();
        for(int i=0;i<n;i++){
            num=((num*10)%a+(b[i]-'0')%a)%a;
        }
        int ans=gcd2(a,num);
        cout<<ans<<endl;
    }
    
    return 0;
}

