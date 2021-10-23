/*APPLICATION OF CONNECTEED COMPONENTS */
#include<iostream>
#define p int(1e9+7)
#define ll long long int
int mat[1001][1001],n,m;
using namespace std;
void input();
void func();
ll fac(ll);
ll dfs(int,int);

int main(){
    int t; cin>>t;
    while(t--)input();
    return 0;
}
void input(){
    int q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){mat[i][j]=0;}}
    int x,y;
    while(q--){
        cin>>x>>y;
        mat[x][y]=1;
    }
    func();
}
void func(){
    ll ans =1;ll t=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j]==1){
                t=dfs(i,j);
                ans=(ans*fac(t))%p;     
            }
        }
    }
    cout<<ans<<endl;
}
ll fac(ll t){
    ll ans =1;
    for(int i=1;i<=t;i++){ ans=(ans*i)%p;}
    return ans%p;
}
bool isValidIndex(int i,int j){
    // for n*m matrix,1 based indexing
    return i>=1 && j>=1 && i<=n && j<=m;
}

ll dfs(int i,int j){ // recursive function calculating number of elements 
//in a single component
    ll t=1;// we have atleast one element in this component
    mat[i][j]=2;//making visited
        if(i-2>=1 && j+1<=m && mat[i-2][j+1]==1)t+=dfs(i-2,j+1);
        if(i-1>=1 && j+2<=m && mat[i-1][j+2]==1)t+=dfs(i-1,j+2);
        if(i+1<=n && j+2<=m && mat[i+1][j+2]==1)t+=dfs(i+1,j+2);
        if(i+2<=n && j+1<=m && mat[i+2][j+1]==1)t+=dfs(i+2,j+1);
        if(i-2>=1 && j-1>=1 && mat[i-2][j-1]==1)t+=dfs(i-2,j-1);
        if(i-1>=1 && j-2>=1 && mat[i-1][j-2]==1)t+=dfs(i-1,j-2);
        if(i+1<=n && j-2>=1 && mat[i+1][j-2]==1)t+=dfs(i+1,j-2);
        if(i+2<=n && j-1>=1 && mat[i+2][j-1]==1)t+=dfs(i+2,j-1);
        return t;
    
}


