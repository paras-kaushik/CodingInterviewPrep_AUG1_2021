#include<iostream>
#include<vector>
#include<utility>
#include<unordered_set>
#define N 100005
using namespace std;
// directed graph
bool checkDirectedCycle(int source,vector<int> adj[],int visited[],int currDfsVisited[]){
    
    visited[source]=1;
    currDfsVisited[source]=1;
    for(auto it :adj[source]){
        if(!visited[it]){
            // go deeper
            if(checkDirectedCycle(it, adj, visited, currDfsVisited)){
                return true;
            }
        }else if(currDfsVisited[it]){
            // its visited ok but is it visited in the current dfs?
            return true;
        }
    }
    currDfsVisited[source]=0;
    
    
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    int visited[V],currDfsVisited[V];
    memset(visited, 0, V*sizeof(int));
    memset(currDfsVisited, 0, V*sizeof(int));
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(checkDirectedCycle(i,adj,visited,currDfsVisited)){
                return true;
            }
        }
    }
    
    
    return false;
   }
