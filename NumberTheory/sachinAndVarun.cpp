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
#include<bitset>
#include <algorithm>
#include<numeric>
typedef unsigned long long  ull;
typedef long long ll;
#define MOD 1000000007
using namespace std;
ll gcd(ll a,ll b)
{
	if(a<b){return gcd(b,a);}
    if(b==0){return a;}
    return gcd(b,a%b); 
}
// Calculating Multiplicative Modulo Inverse - b for whcih (a*b)%m==1
/*
 Above can we written as (ab-1) %m==0 -> ab-1==mq  -> ab-mq==1 where b and q are variables
 In order to solution for exist for above gcd(a,m) divides 1 (Linear Diophantine Equations), only 1 thing divides 1 , 1!
 Now the problem reduces to ab+mQ==gcd(a,m) which is the standard format Extended Euclids solves , using Euclids internally
 acc to Extended Euclids x=y1 and y=x1 -(a/b)y1 is the solution of ax+by=gcd(a,b) given x1 and y1 are solutions of bx1+(a%b)y1=gcd(b,a%b) (Euclids)
 NOTE : for Euclids a should be greater thatn b , then only gcd(a,b)=gcd(b,a%b)
 NOTE: GCD(M,0)==M, GCD(M,1)==1 and EUCLIDS TIME COMPLEXITY is log(max(a,b))
 NOTE: ax=gcd(a,0)==a , has solutions a=1 ,b=0 and gcd==a
 */
class Triplet{
public:
    ll x;
    ll y;
    ll gcd;
};// solution for the standard Extended Euclids Problem ax+by=gcd(a,b)
Triplet extendedEuclid(ll a,ll b){
    if(b==0){ // ax=gcd(a,0)=a
        Triplet ans;
        ans.y=0;
        ans.x=1;
        ans.gcd=a;
        return ans;
    }
    Triplet smallAns=extendedEuclid(b, a%b);//Finding Solution for  bx1+(a%b)y1= gcd(b,a%b)
    // now we have two equations and two variables , below ans is caluldated by comparing coefficients
    Triplet ans;
    ans.x=smallAns.y;
    ans.y=smallAns.x-((a/b)*smallAns.y);
    ans.gcd=smallAns.gcd;
    return ans;
}
ll modInverse(ll a,ll m){
    // this fxn finds b such that (a*b)%m==1
    // above can we writtend as ab+mQ =1 where b and Q are our variables
    // now we know for ex if ax+by=d solution exists only if gcd(a,b) divides d
    //so above gcd(a,m) divides 1 ! so its logically 1
    // therefore above equation is ab+mQ=gcd(a,m) we can solve this via extended euclids, b=x1
    ll x=extendedEuclid(a, m).x;
    return (x%m+m)%m;// as x can also be negative
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        // we have to find number of solutions 
        ll a,b,d;
        cin>>a>>b>>d;// ax+by=d
        ll g=__gcd(a,b);
        a/=g;
        b/=g;
        if(d%g!=0){cout<<"0"<<endl;continue;}// Zero solutions->via LINEAR DIOPANTINE EQUATIONS PROPERTY
        if(d==0){cout<<"1"<<endl;continue;}// x and y are zero
        d/=g;

        ll smallestY=((d%a)*(modInverse(b,a)))%a;
        if(smallestY>(d/b)){
            cout<<"0"<<endl;continue;
        }
        ll n=( ( (d/b) - smallestY) /a);
        cout<<n+1<<endl;

    }
    
    return 0;
}

