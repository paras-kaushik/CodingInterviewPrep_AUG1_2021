
#include <iostream>
#include <vector>
#include<utility>
using namespace std;
const int N = 1e5 + 5;
bool error;
int col[N];
vector<pair<int, int>> adj[N];
void dfs(int start)
{
    int currVertexSet=col[start];
    for (auto edge : adj[start]){
        int adjacentVertex = edge.first;
        int adjacentVertexrelativeValue=edge.second; // if 1 its in different set
        int expectedSetForadjacentVertex=currVertexSet ^ adjacentVertexrelativeValue;
        if (col[adjacentVertex] == -1){
            col[adjacentVertex] = expectedSetForadjacentVertex ;// -1 means unassigned
            dfs(adjacentVertex);
         }
        else if (col[adjacentVertex] != expectedSetForadjacentVertex){
            error = true;
        }
    }
}

int main(){
    int t;cin >> t;
    while (t--){
        int n, m;cin >> n >> m; error = false;
        for (int i = 1; i <= n; i++){adj[i].clear();col[i] = -1;}
        while (m--){
            int a, b, c;cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));adj[b].push_back(make_pair(a, c));}
        for (int i = 1; i <= n; i++){
            if (col[i] == -1){col[i] = 0;dfs(i);}
        }
        if (error)cout << "no" << endl;
        else cout << "yes" << endl;
    }
}


