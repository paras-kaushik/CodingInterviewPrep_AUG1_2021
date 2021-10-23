
#include <iostream>
#include<queue>
using namespace std;

bool hasPathBFS(int** adjMat,int V,int startv,int endv){

bool *visited=new bool[V];//sare vertices ke lie T ya F
  for(int i=0;i<V;i++)
    visited[i]=false;
  
  queue<int> pendingNodes;
  pendingNodes.push(startv);
visited[startv]=true;
  while(pendingNodes.size()){
    int x=pendingNodes.front();pendingNodes.pop();
    if(adjMat[x][endv]==1)// has path is true if they are adj or adj TO ANY adj
        return true;
    for(int i=0;i<V;i++){
      if(i!=x && adjMat[x][i]==1 && !visited[i]){
          visited[i]=true;
          pendingNodes.push(i);
      }
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
  int startv,endv;
  cin>>startv>>endv;
  

    if(hasPathBFS(adjMat,V,startv,endv))
      cout<<"true";
  else
    cout<<"false";
  return 0;
  }
