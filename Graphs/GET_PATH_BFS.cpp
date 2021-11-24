

#include <iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, int> childParentMap;
void printWhoPut(int sv,int ev){
    cout<<ev<<" ";
    if(ev==sv){return;}
    printWhoPut(sv,childParentMap[ev]);
}
//if(getPathBfs(adjMat,V,sv,ev)){
//    printWhoPut(sv,ev);
//}
bool getPathBfs(int **adjMat,int n,int sv,int ev){
   bool* visited=new bool[n];// for all n vertices
    for(int i=0;i<n;i++){visited[i]=false;}
    queue<int> pendingVertices;
    visited[sv]=true;
    pendingVertices.push(sv);
    while(pendingVertices.size()!=0){
        int x=pendingVertices.front();
        pendingVertices.pop();
        if(adjMat[x][ev]==1){
            childParentMap.insert(make_pair(ev, x));// directly adjacent
            return true;
        }
        for(int i=0;i<n;i++){// adjacent to the adjacent elements
            if(i!=x && adjMat[x][i]==1 && !visited[i]){
                visited[i]=true;
                childParentMap.insert(make_pair(i, x));
                pendingVertices.push(i);
            }
        }
    }
    return false;
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
    }//intitially matrix ke sare elements zero
    for(int i=0;i<E;i++){
        int f,s;//first and second vertex
        cin>>f>>s;
        adjMat[f][s]=1;
        adjMat[s][f]=1; //both ways bcoz its undirected graph
    }
    int sv,ev;
    cin>>sv>>ev;
    if(getPathBfs(adjMat,V,sv,ev)){
        printWhoPut(sv,ev);
    }
    
    return 0;
}

