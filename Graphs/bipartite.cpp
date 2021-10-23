#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool bipartite(vector<int>* edges,int n){
    if(n==0)return true;
    
    // we will use vector as queue
    unordered_set<int> sets[2];
    vector<int> pending;// nodes which have unchecked neighbours
    
    sets[0].insert(0);
    pending.push_back(0);
    while(!pending.empty()){
        int current=pending.back();
        pending.pop_back();// its a vector -removing from end is cheaper
        int currentSet=sets[0].count(current)>0? 0:1;
        int l=edges[current].size();
        for(int i=0;i<l;i++){
            int neighbour=edges[current][i];
            // check set of this neighbour
            if(sets[0].count(neighbour)==0 && sets[1].count(neighbour)==0){
                sets[1-currentSet].insert(neighbour);// put it in opposite set
                pending.push_back(neighbour);
            }else if(sets[currentSet].count(neighbour)>0){
                return false;
            }else{
                continue;// the neighbor is already where its supposed to be and also visited/enqueued
            }
        }
    }
    return true;
}
int main(){
    
    while (true) {
        int n;cin>>n;
        if(n==0)break;
        vector<int>* edges=new vector<int>[n];
        int m;cin>>m;
        for(int i=0;i<m;i++){
            int j,k;
            cin>>j>>k;
            edges[j].push_back(k);
            edges[k].push_back(j);
        }
        bool ans=bipartite(edges,n);
        delete [] edges;
        if(ans){cout<<"BICOLORABLE/BIPARTITE"<<endl;}else{
            cout<<"NOT BICOLORABLE/NON BIPARTITE"<<endl;
        }
    }
    
    return 0;
}
