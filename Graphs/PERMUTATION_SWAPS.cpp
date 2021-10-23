#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Application conneced components 
"two elements which can be swapped "
*/

void dfs(int start, vector<int>* edges, int n, unordered_set<int>& visited, unordered_set<int> * component) {
    visited.insert(start);
    component->insert(start);
    vector<int>::iterator it = edges[start].begin();
    for (;it != edges[start].end(); it++) {
        int i = *it;
        if (visited.count(i) > 0) {
            continue;
        }
        dfs(i, edges,n, visited, component);
    }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
    unordered_set<int> visited;
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for (int i = 0; i < n; i++) {
        if (visited.count(i) == 0) {// outer loop on visited array connecting all un-connected components
            unordered_set<int> * component = new unordered_set<int>();
            dfs(i, edges,n, visited, component);
            output->insert(component);
        }
    }
    return output;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        
    int n,m;
    cin >> n>>m;
        vector<int>* edges = new vector<int>[n];// adjaceny list- array of vectors
        int* p =new int[n]();
        int* q= new int[n]();
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            cin>>q[i];
        }
        
    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        edges[j - 1].push_back(k - 1);
        edges[k - 1].push_back(j - 1);
    }
    unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
    // each component is stored as unordered_set<int>* , set of these all sets is needed, that set is pointed at by unordered_set<unordered_set<int>*> *
    
    unordered_set<unordered_set<int>*>::iterator it = components->begin();
        int cannotswapthese=0;
        
    while (it != components->end()) {
        if(cannotswapthese)break;
        
        unordered_set<int>* component = *it;// a single connected component
        unordered_set<int>::iterator it2 = component->begin();
        unordered_set<int> a;
        unordered_set<int> b;
        
        while (it2 != component->end()) {
           // cout << *it2 + 1 << " ";
            a.insert(p[*it2]);
            b.insert(q[*it2]);
            it2++;
        }
        unordered_set<int>::iterator itx=a.begin();
        while(itx!=a.end()){
            if(b.count(*itx)==0){
                cannotswapthese=1;
                break;
            }
            itx++;
        }
        
       // cout << endl;
        delete component;
        it++;
    }
    
    if(cannotswapthese){cout<<"NO"<<endl;}else{cout<<"YES"<<endl;}
    delete components;
    delete [] edges;
    }
}
