#include <iostream>
#include<vector>
using namespace std;
vector<int> getpathdfs(int** adjMat,int V,int E,int* visited,int s,int e){
    visited[s]=true;
    if(s==e)
    {
        vector<int> ans;
        ans.push_back(e);
       
        return ans;
    }
    
    
    vector<int> ans;// NULL VECTOR
    for(int i=0;i<V;i++){
        if(i==s)
            continue;
        if(adjMat[s][i]==1 && visited[i]==false){
        ans=getpathdfs(adjMat, V, E, visited, i, e);
            if(ans.size()>0){
                ans.push_back(s);
               
                return ans;
            }
        }
    }
    

    return ans;
}
int main() {
    int V, E,source,end;
    cin >> V >> E;
    
    int** adjMat=new int*[V];
    for(int i=0;i<V;i++){
        adjMat[i]=new int[V];
        for(int j=0;j<V;j++){
            adjMat[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int s,e;
        cin>>s>>e;
        adjMat[s][e]=1;
        adjMat[e][s]=1;
    }
    cin>>source>>end;
    int* visited=new int[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    vector<int> ans=getpathdfs(adjMat,V,E,visited,source,end);
    
    for(auto const& i:ans){
        cout<<i<<" ";
    }
    
   // cout<<endl;

  return 0;
}
