#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
Node* cloneGraph(Node* node) {
  unordered_set<Node*> visitedNodes;
  queue<Node*> pendingNodes;
  unordered_map<Node*, Node*> originalToNew;
  pendingNodes.push(node);// for bfs
  while(!pendingNodes.empty()){// loop over non visited orignal vertices
      Node* thisNode=pendingNodes.front();
      pendingNodes.pop();
       if(thisNode==NULL)continue;
      Node* newNode=NULL;
      if(visitedNodes.count(thisNode)==0){// when we visit a node we create its clone
          newNode=new Node(thisNode->val);
          originalToNew.insert(make_pair(thisNode, newNode));
          visitedNodes.insert(node);
      }else{
          newNode=originalToNew.at(thisNode);
      }
      
      for(auto it:thisNode->neighbors)
      {
          if(visitedNodes.count(it)==0){// not seen
              Node* newNeighbourNode=new Node(it->val);
              originalToNew.insert(make_pair(it, newNeighbourNode));
              newNode->neighbors.push_back(newNeighbourNode);
              visitedNodes.insert(it);
              pendingNodes.push(it);
             
          }else{
              Node* copiedNeighbour=originalToNew[it];
              newNode->neighbors.push_back(copiedNeighbour);
          }
      }
  }
  return originalToNew[node];
 }

