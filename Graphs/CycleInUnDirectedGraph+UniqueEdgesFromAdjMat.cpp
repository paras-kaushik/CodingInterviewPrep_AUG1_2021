#include<iostream>
#include<vector>
#include<utility>
#include<unordered_set>
#define N 100005
int parent[N],ranks[N];// for union find by rank and path compression
using namespace std;

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
bool isCycle(int V, vector<int> adj[]) { //1 ≤ V, E ≤ 105
    for (int i = 0; i < V; i++) { parent[i] = i;}// all ranks are already zero (as global)
    unordered_set<int>* uniqAdj=new unordered_set<int>[V] ;
    for(int i=0;i<V;i++){
           vector<int> adjacentElementsList=adj[i];
           int n=adjacentElementsList.size();
           for(int j=0;j<n;j++){
               int neighbour=adj[i][j];
               int s=min(neighbour,i);
               int e=max(neighbour,i);
               if(uniqAdj[s].count(e)==0){
                   uniqAdj[s].insert(e);
                   //cout<<s<<" "<<e<<endl;
                   if(getParent(s)==getParent(e)){
                       return true;
                   }else{
                       unionFindByRank(s,e);
                   }
               }
           }
       }
    
    delete [] uniqAdj;
   return false;
}
