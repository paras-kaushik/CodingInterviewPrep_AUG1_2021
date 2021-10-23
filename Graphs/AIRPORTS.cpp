
#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
public:
    int source;
    int destination;
    int weight;
    
    Edge(){
        this->source=-1;
        this->destination=-1;
        this->weight=-1;
        
    }
    
    Edge(int s,int d,int w){
        this->source=s;
        this->destination=d;
        this->weight=w;
        
    }
    
};

bool wayToSort(Edge e1,Edge e2)
{ return e2.weight > e1.weight; }

int getParent(int* parent,int v){
    if(parent[v]==v)
        return v;
    v=parent[v];
    return getParent(parent,v);
}


int main(){
    int t;cin>>t;
    int c=1;
    while(t--){
    int V, E,A;
    cin >> V >> E>> A;
    Edge input[E];
    Edge output[V-1];// our final road network
    //1 take input
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i]=Edge(s-1,d-1,w);
    }
    //2 sort the array
    sort(input,input+E,wayToSort);
    
    int parent[V];
        for(int i=0;i<V;i++){parent[i]=i;}
    int count=0;

    for(int i=0;i<E;i++){
        //count<V-1
       int v1=input[i].source;
        int v2=input[i].destination;
        int edgeWeight=input[i].weight;
        int p1=getParent(parent,v1);
        int p2=getParent(parent,v2);
        if(p1==p2)
            continue;// makes a cycle
        if(p1!=p2){
            if(edgeWeight+A<(2*A)){
                output[count]=input[i];
                count++;
                parent[p1]=p2;
                
            }
        }
    }
        int sum=0;
    for(int i=0;i<count;i++){
        sum+=output[i].weight;
    }
        
        
        int numAirport = 0;
                for(int i = 0; i < V; i++)
                {
                    if(parent[i] == i)
                        numAirport++;
                }
        sum+=(numAirport*A);
        cout<<"Case #"<<c<<": "<<sum<<" "<<numAirport<<endl;
        c++;
}
    return 0;
}

/*
 1
 20 8 27
 14 9 31
 4 14 1
 9 15 26
 13 3 27
 12 5 41
 10 13 14
 6 13 8
 4 13 8
 
 1
 3 2 7
 1 2 5
 2 3 7
 **/

