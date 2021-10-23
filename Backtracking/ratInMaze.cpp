
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
typedef unsigned long long  ull;
typedef long long ll;
#define MOD 1000000007
using namespace std;
//print all paths that rat can follow to reach maze[N-1][N-1]
int sol[120][120];
void printmtr(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sol[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<endl;
}
void rathelper(int maze[][20],int x,int y,int n){
    
    if(x <0 || x>=n || y<0 || y>=n ||
       sol[x][y]==1 ||
       maze[x][y]==0){
        return;
    }
    if(x==n-1 && y==n-1){sol[x][y]=1;printmtr(n);sol[x][y]=0;return;}
    sol[x][y]=1;
    rathelper(maze,x-1,y,n);
    rathelper(maze,x+1,y,n);
    rathelper(maze,x,y+1,n);
    rathelper(maze,x,y-1,n);
    sol[x][y]=0;
}
void ratInAMaze(int maze[][20], int n){
//LRUD, 0 means blocked , and cannot visit one cell twice in path
    memset(sol, 0, 120*120*sizeof(int));
    rathelper(maze,0,0,n);
 

}
// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int n;
//   cin >> n ;
//   int maze[20][20];
//   for(int i = 0; i < n ;i++){
//     for(int j = 0; j < n; j++){
//             cin >> maze[i][j];
//         }
//   }
//   ratInAMaze(maze, n);
// }


