#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> getpathbfs(int** adjMat,int V,int E,int s,int e){
    
    int* visited=new int[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    vector<int> ans;
    queue<int> pendingnodes;
    unordered_map<int, int> m;
    pendingnodes.push(s);
    
    while (!pendingnodes.empty()) {
        int sv=pendingnodes.front();
        visited[sv]=true;
        pendingnodes.pop();
        if(adjMat[sv][e]){
    
            m.insert(make_pair(e,sv));
            break;
        }
        for(int i=0;i<V;i++){
            if(i==sv)
                continue;
            if(adjMat[sv][i]==1 && !visited[i]){
                pendingnodes.push(i);
                m.insert(make_pair(i, sv));
            }
        }
    }
    if(m.find(e)!=m.end())
        ans.push_back(e);
    while(m.find(e)!=m.end()){
        //ans.push_back(e);
        ans.push_back(m[e]);
        if(m[e]==s)
            break;
        e=m[e];
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
    
    vector<int> ans=getpathbfs(adjMat,V,E,source,end);
    for(auto const& i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

  return 0;
}
