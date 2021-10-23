
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

int board[11][11];
bool isPossible(int n,int r,int c ){
    // in an n*n board is it possible to place queen on the (r,c) index ?
    for(int i=r-1;i>=0;i--){
        if(board[i][c]==1){return false;}
    }
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
       if(board[i][j]==1){return false;}
    }
    for(int i=r-1,j=c+1;i>=0&&(j<n);i--,j++){
        if(board[i][j]==1){return false;}
    }
    return true;
}
void printmtr(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
       // cout<<endl;
    }
    cout<<endl;
}
void queenHelper(int n,int row){
    if(row==n){// 0 to n-1 rows have been filled with a queen
        printmtr(n);
        return;
    }
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j]=1;
            queenHelper(n,row+1);// place in next row
            board[row][j]=0;
        }
    }
}

void placeNQueens(int n){
    memset(board, 0, 11*11*sizeof(int));
    queenHelper(n,0);
}


