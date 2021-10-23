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
void dfs(vector<int>* edges,int start,bool* visited,stack<int>& finishStack ){
    //visited.insert(start);
    visited[start]=true;
    int l=edges[start].size();
    for(int i=0;i<l;i++){
        int adjacent=edges[start][i];
        if(!visited[adjacent]){
            dfs(edges, adjacent, visited, finishStack);
        }
    }
    finishStack.push(start);// pushed in stack when all its adjacent calls are finished
}
void dfs2(vector<int>* edges,int start,unordered_set<int>* component,bool* visited){
    visited[start]=true;
    component->insert(start);
    int l=edges[start].size();
    for(int i=0;i<l;i++){
        int adjacent=edges[start][i];
        if(!visited[adjacent]){
            dfs2(edges, adjacent, component, visited);
        }
    }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    stack<int> finishedVertices;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(edges,i,visited,finishedVertices);
        }
    }
    // stack is ready
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    while(!finishedVertices.empty()){
        int element=finishedVertices.top();
        finishedVertices.pop();
        if(visited[element]){continue;}
        unordered_set<int>* component=new unordered_set<int>();
        dfs2(edgesT,element,component,visited);
        output->insert(component);
    }
    return output;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
    int n;cin>>n;
    vector<int>* edges=new vector<int>[n];
    vector<int>* edgesT=new vector<int>[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int j,k;cin>>j>>k;
        edges[j-1].push_back(k-1);// its a directed graph
       // edgesT[k-1].push_back(j-1);
        edgesT[j-1].push_back(k-1);
    }
    unordered_set<unordered_set<int>*>* components=getSCC(edges,edgesT,n);
    
    
//     unordered_set<unordered_set<int>*>::iterator it=components->begin();
       
//        while(it!=components->end()){
//            unordered_set<int>* thiscompo=*it;
//            unordered_set<int>::iterator cit=thiscompo->begin();
//            while(cit!=thiscompo->end()){
//                cout<<*cit+1<<" ";
//                cit++;
//            }
//            cout<<endl;
//            delete thiscompo;
//            it++;
//        }
    
    cout<<components->size()<<endl;
    
    
    delete components;// deleting pointer
    delete [] edges;// deleting array pointer
    delete [] edgesT;
    }
    return 0;
}


