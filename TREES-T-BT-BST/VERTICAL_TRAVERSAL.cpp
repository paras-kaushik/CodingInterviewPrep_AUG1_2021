
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include <utility>
using namespace std;
 
  struct TreeNode { //Definition for a binary tree node.
      int val;
      TreeNode *left; TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> allNodesFoundInIncreasingOrderof_y_in_increasingOrderOf_x;
        map<int,map<int,multiset<int>>> nodesfor_x_by_y_level;
        queue<pair<TreeNode*,pair<int, int>>> node_xy;
        node_xy.push({root,{0,0}});
        while (!node_xy.empty()) {
            auto p=node_xy.front();node_xy.pop();
            TreeNode* currNode=p.first;
            int x=p.second.first , y=p.second.second;
            nodesfor_x_by_y_level[x][y].insert(currNode->val);
            if(currNode->left!=NULL){
                node_xy.push({currNode->left,{x-1,y+1}});
            }
            if(currNode->right!=NULL){
                node_xy.push({currNode->right,{x+1,y+1}});
            }
        }
        for(auto p:nodesfor_x_by_y_level){// map keys (x) are already sorted by map
            vector<int> nodes_for_this_y_vec;
            for(auto q:p.second){
                int y=q.first;
                multiset<int> nodes_for_this_y=q.second;
                
                for(auto it:nodes_for_this_y){
                    nodes_for_this_y_vec.push_back(it);
                }
            }
            allNodesFoundInIncreasingOrderof_y_in_increasingOrderOf_x.push_back(nodes_for_this_y_vec);
        }
        return allNodesFoundInIncreasingOrderof_y_in_increasingOrderOf_x;
    }
};
int main(){
    return 0;
}

