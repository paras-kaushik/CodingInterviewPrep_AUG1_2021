
/*
IF YOU USE AN ADJACENCY MATRIX HERE YOU WILL GET A TLE !!!
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
0 ≤ M ≤ 10^5
0 ≤ Ai ≤ 10^12
*/
#include <iostream>
#include<queue>
typedef unsigned long long ull;
using namespace std;
ull sumofComponent=0;

//void printBfs(ull **adjMat,ull n,ull sv,bool* visited,ull*a){
void printBfs(vector<ull>* adl,ull n,ull sv,bool* visited,ull*a){
    queue<ull> pendingVertices;
       visited[sv]=true;
    pendingVertices.push(sv);
    while(pendingVertices.size()!=0){
        ull x=pendingVertices.front();
          //cout<<x<<" ";
        sumofComponent+=a[x];
        pendingVertices.pop();
//        for(ull i=0;i<n;i++){
//            if(i!=sv && adjMat[x][i]==1 && !visited[i]){//adjacent and not visited
//                visited[i]=true;
//                pendingVertices.push(i);
//            }
//        }
        ull n=adl[x].size();
        
        for(ull i=0;i<n;i++){
          ull adjacentVertex=adl[x][i];
            if(!visited[adjacentVertex]){
                visited[adjacentVertex]=true;
                pendingVertices.push(adjacentVertex);
            }
        }
    }
}
ull overallcomponentSum=0;
//void bfsHelper(ull **adjMat,ull n,ull* a){// n is number of vertices
void bfsHelper(vector<ull>* adl,ull n,ull* a){// n is number of vertices
    
    bool* visited=new bool[n];// for all n vertices
    for(ull i=0;i<n;i++){visited[i]=false;}
    for(ull i=0;i<n;i++){
        if(!visited[i]){
            sumofComponent=0;
            //printBfs(adjMat,n,i,visited,a);
            printBfs(adl,n,i,visited,a);
            
            overallcomponentSum=max(overallcomponentSum,sumofComponent);
        }
    }
}

int main() {
    ull t;
    cin>>t;
    while(t--){
    ull V, E;
    cin >> V >> E;
//  ull** adjMat=new ull*[V]; //ajd matrix is size v*v
//  for(ull i=0;i<V;i++){
//    adjMat[i]=new ull[V];
//    for(ull j=0;j<V;j++){
//      adjMat[i][j]=0;
//    }
//  }
        vector<ull>* adl=new vector<ull>[V];//ARRAY OF VECTORS
        
    //intitially matrix ke sare elements zero
    for(ull i=0;i<E;i++){
      ull f,s;//first and second vertex
      cin>>f>>s;
//      adjMat[f-1][s-1]=1;
//      adjMat[s-1][f-1]=1; //both ways bcoz its undirected graph
        
        adl[f-1].push_back(s-1);
        adl[s-1].push_back(f-1);
        
    }
        // for(ull i=0;i<V;i++){
        //     ull n=adl[i].size();
        //     if(n>0){
        //         cout<<i<<": ";
        //         for(ull j=0;j<n;j++){
        //             cout<<adl[i][j]<<"";
        //         }
        //         cout<<endl;
        //     }
        // }
        
        
        ull*a=new ull[V]();
        for(ull i=0;i<V;i++){
            cin>>a[i];// vetex weight
        }
        overallcomponentSum=0;
   // bfsHelper(adjMat,V,a);
        bfsHelper(adl,V,a);
        cout<<overallcomponentSum<<endl;
        delete [] a;
        delete [] adl;
//        for(ull i=0;i<E;i++){
//            delete [] adjMat[i];
//        }
//        delete [] adjMat;
//
        
    }
  return 0;
  }



