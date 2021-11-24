#include<iostream>
#include<utility>
#include<vector>
using namespace std;
#define int long long
#define realint int
#define pb push_back
#define pii pair<int,int>
#define N 100005
#define MOD 1000000007
int src[N], dest[N],val[N],idx[N];

int parent[N],ranks[N];// for union find by rank and path compression

int par[N], discovery[N], low[N],visited[N],isArticulationPoint[N],timer=0;// for BRIDGE ALGO

vector<vector<pii>> adjacencyListWithWeight(N);
int edgeStatus[N];// 0-> NONE , 1-> SOME ,2 -> EVERY


void bridgedfs(int source){
    discovery[source]=low[source]=timer;
    visited[source]=true;
    timer++;
    int count =0;// for original source and original source only
    for(pii p :adjacencyListWithWeight[source]){
        int neighbour=p.first;// bridge algo has no matlab with weight
        if(neighbour==parent[source]){
            continue;// we have to see by ignoring orignal path taken ->ye node sabse lowest konse dicovered bande ko touch kar sakta hai, so parent path is of no use
        }else if(visited[neighbour]){
            low[source]=min(low[source],discovery[neighbour]);
        }else{
            par[neighbour]=source; count++;
            bridgedfs(neighbour);
            low[source]=min(low[source],low[neighbour]);
            if(parent[source]==-1){// its orininal source
                if(count>=2){
                    isArticulationPoint[source]=true;
                }
            }else{
                if(low[neighbour]>=discovery[source]){
                    isArticulationPoint[source]=true;
                }
            }
        }
    }
}

int getParent(int node){
    if(node==parent[node]){
        return node;
    }
    parent[node]=getParent(parent[node]);// path compression
    return parent[node];
}

void unionFindByRank(int u,int v){
    int p1=getParent(u);
    int p2=getParent(v);
    
    int rp1=ranks[p1];
    int rp2=ranks[p2];
    
    if(rp1>rp2){// higher rank is parent
        parent[p2]=p1;
    }else if(rp2>rp1){
        parent[p1]=p2;
    }else{
        parent[p1]=p2;
        ranks[p2]++;
    }
}
void solve(){
    int v,e;
    cin>>v>>e;
    for (int i = 1; i <= e; i++) {
          cin >> src[i] >> dest[i] >> val[i];
          idx[i] = i;
      }
      // sort idx array based on weight/value
      sort(idx + 1, idx + e + 1, [&](int x, int y) {
          return val[x] < val[y];
      });
      for (int i = 1; i <= e; i++) { parent[i] = i;}// all ranks are already zero (as global)
    
   
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

