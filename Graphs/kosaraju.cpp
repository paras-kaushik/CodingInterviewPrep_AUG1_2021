/*
 KOSARAJUS ALGO FOR FINDING "STRONGLY "CONNECTED COMPONENTS in DIRECTED GRAPHS
 "STRONGLY "-> within a component all vertices will have path with each other
 **/
#include<iostream>
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
void dfs(vector<int>* edges,int start,unordered_set<int>& visited,stack<int>& finishStack ){
    visited.insert(start);
    int l=edges[start].size();
    for(int i=0;i<l;i++){
        int adjacent=edges[start][i];
        if(visited.count(adjacent)==0){
            dfs(edges, adjacent, visited, finishStack);
        }
    }
    finishStack.push(start);// pushed in stack when all its adjacent calls are finished
}
void dfs2(vector<int>* edges,int start,unordered_set<int>* component,unordered_set<int> &visited){
    visited.insert(start);
    component->insert(start);
    int l=edges[start].size();
    for(int i=0;i<l;i++){
        int adjacent=edges[start][i];
        if(visited.count(adjacent)==0){
            dfs2(edges, adjacent, component, visited);
        }
    }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
    unordered_set<int> visited;
    stack<int> finishedVertices;
    
    for(int i=0;i<n;i++){
        if(visited.count(i)==0){
            dfs(edges,i,visited,finishedVertices);
        }
    }
    // stack is ready
    visited.clear();
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    while(!finishedVertices.empty()){
        int element=finishedVertices.top();
        finishedVertices.pop();
        if(visited.count(element)!=0){continue;}
        unordered_set<int>* component=new unordered_set<int>();
        dfs2(edgesT,element,component,visited);
        output->insert(component);
    }
    return output;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int>* edges=new vector<int>[n];
    vector<int>* edgesT=new vector<int>[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int j,k;cin>>j>>k;
        edges[j-1].push_back(k-1);// its a directed graph
        edgesT[k-1].push_back(j-1);
    }
    unordered_set<unordered_set<int>*>* components=getSCC(edges,edgesT,n);
    
    
    unordered_set<unordered_set<int>*>::iterator it=components->begin();
       
       while(it!=components->end()){
           unordered_set<int>* thiscompo=*it;
           unordered_set<int>::iterator cit=thiscompo->begin();
           while(cit!=thiscompo->end()){
               cout<<*cit+1<<" ";
               cit++;
           }
           cout<<endl;
           delete thiscompo;
           it++;
       }
    
    
    
    
    delete components;// deleting pointer
    delete [] edges;// deleting array pointer
    delete [] edgesT;
    return 0;
}
