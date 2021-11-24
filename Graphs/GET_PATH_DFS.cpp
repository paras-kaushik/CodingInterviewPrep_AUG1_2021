#include <iostream>
#include<vector>
using namespace std;
vector<int> getPath(int** adjMat,int V,int startV,int endV,bool* visited){
    vector<int> myPath;
    visited[startV]=true;
    if(startV==endV){
        myPath.push_back(endV);
        return myPath;
    }
    for(int i=0;i<V;i++){
        if(i!=startV && adjMat[startV][i]==1 && !visited[i]){
            vector<int> smallans=getPath(adjMat,V,i,endV,visited);
            if(smallans.size()>0){
                smallans.push_back(startV);
                return smallans;
            }
        }
    }
    return myPath;
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int **adjMat=new int*[V];
    
    for(int i=0;i<V;i++){
        adjMat[i]=new int[V];
        for(int j=0;j<V;j++)
            adjMat[i][j]=0;
    }
    for(int i=0;i<E;i++){
        cin>>tempX>>tempY;
        adjMat[tempX][tempY]=1;
        adjMat[tempY][tempX]=1;//its an undirected graph
    }
    int startV,endV;
    cin>>startV>>endV;
    bool* visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    ;
    for(auto it:getPath(adjMat,V,startV,endV,visited)){
        cout<<it<<" ";
    }
    
    return 0;
}

