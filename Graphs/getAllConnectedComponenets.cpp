/*
 Finding Connected components in undirected graph
 */
#include<iostream>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
void dfs(vector<int>* edges,//  DFS on a adjacency list
         int s,int n,
         set<int>* component,
         bool* visited){
    
    visited[s]=true;
    component->insert(s);
    int l=edges[s].size();
    for(int i=0;i<l;i++){// all adjacent vertices of vertex s are in vector edges[s]
        int next=edges[s][i];
        if(!visited[next])
        dfs(edges, edges[s][i], n, component, visited);
    }
}
set<set<int>*>* getComponenets(vector<int>* edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    set<set<int>*>* output=new set<set<int>*>();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            set<int>* component=new set<int>();
            dfs(edges,i,n,component,visited);
            output->insert(component);
        }
    }
    delete [] visited;
    
    return output;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>* edges=new vector<int>[n];// array of vectors-ADjList
    
    for(int i=0;i<m;i++){
        int j,k;
        cin>>j>>k;
        edges[j].push_back(k);
        edges[k].push_back(j);
    }
    set<set<int>*>* components=getComponenets(edges,n);
    // pointer to set pointers
    set<set<int>*>::iterator it=components->begin();
    
    while(it!=components->end()){
        set<int>* thiscompo=*it;
        set<int>::iterator cit=thiscompo->begin();
        while(cit!=thiscompo->end()){
            cout<<*cit<<" ";
            cit++;
        }
        cout<<endl;
        it++;
    }
    delete components;
    
    return 0;
}


