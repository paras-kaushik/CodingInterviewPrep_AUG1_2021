// count all non empty cells ie 1's and 2's
// Store all rotten oranges in the Queue
// POP AND ROT ALL ADJACENT, PUSH newly rotten in queue
//  The nnumber of levels in BFS in the answer
// if number of elements inserted in queue is equal to count of all non empty cells ie 1's and 2's= return level else -1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#define pii pair<int,int>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty())return 0;
    int m=grid.size(),n=grid[0].size(),days=0,tot=0,cnt=0;
    queue<pii> rottens;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=0)tot++;
            if(grid[i][j]==2){rottens.push({i,j});}
        }
    }
    int dx[4]={0,0,1,-1}; int dy[4]={1,-1,0,0};// UP DOWN LEFT RIGHT
    while (!rottens.empty()) {
        int k=rottens.size();
        cnt+=k;
        while(k--){// these k oranges start rotting adjacent on the same day !!
            int x=rottens.front().first , y=rottens.front().second;
            rottens.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i] , ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1){continue;}
                grid[nx][ny]=2;// 1->2
                rottens.push({nx,ny});
            }
        }
        if(!rottens.empty())days++;
    }
    return tot==cnt? days:-1;
}
