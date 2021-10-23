template <typename T>
class TreeNode {
    TreeNode<T>** children;
    int childCount;int maxChildCount;// same as capacity
    public:
        T data;
        TreeNode(T data) {
            this->data = data;
            childCount = 0;
            maxChildCount = 10;
            children = new TreeNode<T>*[10];
        }
        int numChildren() {return childCount;}
        void addChild(TreeNode<T>* child) {
            children[childCount] = child;
            childCount++;
            if(childCount == maxChildCount) {// we dont have capacity of entering next element this means
                TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
                for(int i = 0; i < maxChildCount; i++) {
                    childrenNew[i] = children[i];
                 }
                 maxChildCount *= 2;
                children = childrenNew;
            }
        }
        TreeNode<T>* getChild(int index) { return children[index];}
        void setChild(int index, TreeNode<T>* child) {children[index] = child;}
};

template <typename T>
class Queue {
    T* data;
    int capacity,nextIndex,firstIndex,length;

    public:
        Queue() {
            capacity = 10;
            data = new T[capacity];
            length = 0;
            nextIndex = 0;
            firstIndex = -1;
        }

        int size() {return length;}
        bool isEmpty() {return length == 0;}

        T front() {
            if (length == 0) {return 0;}
            return data[firstIndex];
        }

        T dequeue() {
            if (length == 0) {return 0;}

            T output = data[firstIndex];
            length--;
            firstIndex = (firstIndex + 1)%capacity;
            if (length == 0) {
                firstIndex = -1;
                nextIndex = 0;
            }
            return output;
        }

        void enqueue(T element) {
            if (length == capacity) {
                T* temp = data;
                capacity = 2* capacity;
                data = new T[capacity];
                int k = 0;
                for (int i = firstIndex; i < length; i++) {
                    data[k] = temp[i];
                    k++;
                }
                for (int i = 0; i < firstIndex; i++) {
                    data[k] = temp[i];
                    k++;
                }
                delete [] temp;
                firstIndex = 0;
                nextIndex = length;
            }
            data[nextIndex] = element;
            length++;
            nextIndex = (nextIndex + 1) % capacity;
            if (firstIndex == -1) {
                firstIndex = 0;
            }
        }
        ~Queue() {
            delete [] data;
        }
};
#include <iostream>
using namespace std;
TreeNode<int>* takeInputLevelWise() {
    Queue<TreeNode<int>*> q;
    int rootData;

    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    q.enqueue(root);
    while (!q.isEmpty()) {
        TreeNode<int>* frontNode = q.dequeue();

        int numChildren;
        cin >> numChildren;
        for (int i = 0; i < numChildren; i++) {

            int childData;
            cin >> childData;
            TreeNode<int>* childNode = new TreeNode<int>(childData);
            q.enqueue(childNode);
            frontNode->addChild(childNode);
        }
    }
    return root;
}
//find and return the node for which sum of data of all immidiate children and the node itself is maximum.

int nodeSum(TreeNode<int>* root){
    int thisans=root->data;
    int n=root->numChildren();
    for(int i=0;i<n;i++){
        thisans+=root->getChild(i)->data;
    }
    return thisans;
}


TreeNode<int>* maxSumNode(TreeNode<int> *root){
    if(root==NULL)return NULL;
    int thisans=nodeSum(root);
    TreeNode<int>* ans=root;
    int n=root->numChildren();
    for(int i=0;i<n;i++){
        TreeNode<int>* potentialAns=maxSumNode(root->getChild(i));
        if(nodeSum(potentialAns)>thisans){
            ans=potentialAns;
        }
      
    }
    return ans;

}




bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2) {
    if(root1==NULL && root2==NULL)return true;
    if(root1==NULL || root2==NULL)return false;
    int v1=root1->data;
    int v2=root2->data;
    int n1=root1->numChildren();
    int n2=root2->numChildren();
    if(v1!=v2  ||  n1!=n2)return false;
    
    for(int i=0;i<n1;i++){
        if(!isIdentical(root1->getChild(i), root2->getChild(i))){
            return false;
        }
    }
    
    return true;
}

class cl{
    public:
    TreeNode <int>* node;
    int max;
    int smax;
    
    cl(TreeNode <int>* node,
       int max,
       int smax){
        this->node=node;
        this->max=max;
        this->smax=smax;
    }
    
};
#include<climits>
#include<cmath>
#include<utility>
#include<set>
#include<map>
void help(map<int,TreeNode <int>*>& valuePointerMap,TreeNode<int> *root){
    if(root==NULL) return;
    valuePointerMap[root->data]=root;
    int n=root->numChildren();
    for(int i=0;i<n;i++){
        help(valuePointerMap, root->getChild(i));
    }

}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    map<int,TreeNode <int>*> valuePointerMap;
    help(valuePointerMap,root);
    TreeNode <int>* s=NULL;
    int n=valuePointerMap.size();
    int i=1;
    for(auto it: valuePointerMap){
        int k=(it.first);
        if(i==n-1)
            cout<<(k)<<"->.  "<<it.second<<endl;
        i++;
    }
    return s;
}

void help(TreeNode<int> *root, int d){
    if(root==NULL) return;
    root->data=d;
    int n=root->numChildren();
    for(int i=0;i<n;i++){
        help(root->getChild(i),d+1);
    }
        
}
void replaceWithDepthValue(TreeNode<int> *root){
    // Write your code here
    help(root,0);
}







