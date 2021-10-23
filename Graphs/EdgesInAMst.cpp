
#include <iostream>
#include <vector>
#include <algorithm>
#define N 100001
using namespace std;
int V, E, startVertex[N], endVertex[N], weights[N], originalIndex[N];
int ans[N], visited[N], h[N], parents[N], lowestTimeOfInsertion[N];
vector<pair<int, int>> adjacencyListWithOriginalIndex[N];
bool cmp(const int &x, const int &y)
{
    return weights[x] < weights[y];
}
int findparent(int x)
{// initally everyone has parent as vertex 0, we are not using that vertex to represent anything
    while (parents[x]!=0)
        x = parents[x];
    return x;
}
void uni(int x, int y)
{
    x = findparent(x);
    y = findparent(y);
    adjacencyListWithOriginalIndex[x].clear();
    adjacencyListWithOriginalIndex[y].clear();
    visited[x] = 0;
    visited[y] = 0;
    if (x == y)
        return;
    if (h[x] > h[y])
        parents[y] = x;
    else
    {
        parents[x] = y;
        if (h[x] == h[y])
            h[y]++;
    }
}
void add_edge(int parentofvertex1, int parentofvertex2, int i)
{
   // cout<<" "<<parentofvertex1<<" "<<parentofvertex2<<" "<<i<<endl;
    if (parentofvertex1 == parentofvertex2)
        return;
    
    ans[i] = 1;//"at least one"
    adjacencyListWithOriginalIndex[parentofvertex1].push_back({parentofvertex2, i});
    adjacencyListWithOriginalIndex[parentofvertex2].push_back({parentofvertex1, i});
}
void kruskal(int sv, int originalParentIndex, int time)
{
    cout<<sv<<" "<<originalParentIndex<<endl;
    visited[sv] = true;
    lowestTimeOfInsertion[sv] =time;
    for (pair<int, int> i : adjacencyListWithOriginalIndex[sv]){
        int adjacent=i.first;
        int originalIndex=i.second;
        if (!visited[adjacent])
        {
            kruskal(adjacent, originalIndex, time + 1);
            lowestTimeOfInsertion[sv] = min(lowestTimeOfInsertion[sv], lowestTimeOfInsertion[i.first]);
        }
        else if (originalIndex != originalParentIndex)
            lowestTimeOfInsertion[sv] = min(lowestTimeOfInsertion[sv], lowestTimeOfInsertion[i.first]);
    }
    if (lowestTimeOfInsertion[sv] == time)//any
        ans[originalParentIndex] = 2;
}
int main()
{
    cin >> V >> E;
    for (int i = 1; i <= E; i++)
    {
        cin >> startVertex[i] >> endVertex[i] >> weights[i];
        originalIndex[i] = i;
    }
    sort(originalIndex + 1, originalIndex + E + 1, cmp);// we started originalIndex array from 1 we sort it according to weights array !
    for (int i = 1; i <= E;)
    {
        int j;
        for (j = i; weights[originalIndex[j]] == weights[originalIndex[i]]; j++){// will process all of same weight together
            add_edge(findparent(startVertex[originalIndex[j]]),
                     findparent(endVertex[originalIndex[j]]),
                     originalIndex[j]);
            
        }
        for (j = i; weights[originalIndex[j]] == weights[originalIndex[i]]; j++)
        {
            int k = findparent(startVertex[originalIndex[j]]);
            if (!visited[k])
                kruskal(k, 0, 0);
        }
        for (j = i; weights[originalIndex[j]] == weights[originalIndex[i]]; j++)
            uni(startVertex[originalIndex[j]], endVertex[originalIndex[j]]);
        i = j;
    }
    for (int i = 1; i <= E; i++)
        if (!ans[i])
            cout << "none" << endl;
        else if (ans[i] == 1)
            cout << "at least one" << endl;
        else
            cout << "any" << endl;
    return 0;
}



