
#include <iostream>
#include<queue>
using namespace std;


void printBfs(int **adjMat,int n,int sv,bool* visited){

    queue<int> pendingVertices;
   	visited[sv]=true;
    pendingVertices.push(sv);
    while(pendingVertices.size()!=0){
        int x=pendingVertices.front();
      	cout<<x<<" ";
        pendingVertices.pop();
        for(int i=0;i<n;i++){
            if(i!=sv && adjMat[x][i]==1 && !visited[i]){//adjacent and not visited
                visited[i]=true;
                pendingVertices.push(i);
            }
        }
    }
}
void bfsHelper(int **adjMat,int n){// n is number of vertices
    bool* visited=new bool[n];// for all n vertices
	for(int i=0;i<n;i++){visited[i]=false;}
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBfs(adjMat,n,i,visited);
        }
    }
    
}

int main() {
    int V, E;
    cin >> V >> E;
  int** adjMat=new int*[V]; //ajd matrix is size v*v

  for(int i=0;i<V;i++){
    adjMat[i]=new int[V];
    for(int j=0;j<V;j++){
      adjMat[i][j]=0;
    }
  }
    //intitially matrix ke sare elements zero

    for(int i=0;i<E;i++){
      int f,s;//first and second vertex
      cin>>f>>s;
      adjMat[f][s]=1;
      adjMat[s][f]=1; //both ways bcoz its undirected graph

    }
  

    bfsHelper(adjMat,V);
  return 0;
  }
