#include<iostream>
#include<vector>
#include<utility>
#define N 100005
int parent[N],ranks[N];// for union find by rank and path compression
using namespace std;
int checkMat[1000][1000];

int getParent(int node){
    if(node==parent[node]){
        return node;
    }
    parent[node]=getParent(parent[node]);// path compression
    return parent[node];
}

void unionFindByRank(int u,int v){
    int p1=getParent(u);
    int p2=getParent(v);
    
    int rp1=ranks[p1];
    int rp2=ranks[p2];
    
    if(rp1>rp2){// higher rank is parent
        parent[p2]=p1;
    }else if(rp2>rp1){
        parent[p1]=p2;
    }else{
        parent[p1]=p2;
        ranks[p2]++;
    }
}
bool isCycle(int V, vector<int> adj[]) {
   vector<pair<int, int>> uniqueEdges;
   memset(checkMat, -1, 1000*1000*sizeof(int));
   for(int i=0;i<V;i++){
       vector<int> adjacentElementsList=adj[i];
       int n=adjacentElementsList.size();
       for(int j=0;j<n;j++){
           int neighbour=adj[i][j];
           if(checkMat[i][neighbour]==-1 && checkMat[neighbour][i]==-1){
               uniqueEdges.push_back(make_pair(i, neighbour));
               checkMat[i][neighbour]=1 ;
               checkMat[neighbour][i]=1;
           }
       }
   }
    for (int i = 0; i < V; i++) { parent[i] = i;}// all ranks are already zero (as global)
    int n=uniqueEdges.size();
   for(int i=0;i<n;i++){
       int s=uniqueEdges[i].first;
       int e=uniqueEdges[i].second;
       if(getParent(s)==getParent(e)){
           return true;
       }else{
           unionFindByRank(s,e);
       }
   }
   return false;
}
