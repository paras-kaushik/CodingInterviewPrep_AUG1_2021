
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


class p{
    public:
    int h;
    int isbal;
    
    p(int h,int isbal){
        this->h=h;
        this->isbal=isbal;
    }
};
p* help(BinaryTreeNode<int> *root){
    if(root==NULL) {return new p(0,true);}
    if(root->left==NULL && root->right==NULL){
        return new p(1,true);
    }
    p* leftans=help(root->left);
    p* rightans=help(root->right);
    int lh=leftans->h;
    int rh=rightans->h;
    
   bool thisans=(abs(lh-rh)<=1 && leftans->isbal && rightans->isbal);
    
    return new p(1+lh+rh,thisans);
    
}
bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    return help(root)->isbal;

}



#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL) return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    //NULL now means end of the level-> print new line and enque NULL
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *temp=pendingNodes.front();
        pendingNodes.pop();
        if(temp==NULL){
            if(!pendingNodes.empty()){
                cout<<endl;
                pendingNodes.push(NULL);// As prev node has definaltely enqueued its children already
            }
            continue;
        }
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        pendingNodes.push(temp->left);
        if(temp->right!=NULL)
        pendingNodes.push(temp->right);
    }
}
template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

//return  array which contains head of each level linked list.
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<Node<int>*>  allheads;
    
    if(root==NULL) return allheads;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    //NULL now means end of the level-> print new line and enque NULL
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
while(!pendingNodes.empty()){
    BinaryTreeNode<int> *temp=pendingNodes.front();
    pendingNodes.pop();
    allheads.push_back(head);
    head=NULL;
    tail=NULL;
    if(temp==NULL){// this level ENDS
        if(!pendingNodes.empty()){
            //cout<<endl;
           
            pendingNodes.push(NULL);// As prev node has definaltely enqueued its children already
        }// if queue is empty that means there is no further level as we can see no elements are enqueued
        continue;
    }
    //Insert in active ll
    if(head==NULL){
        head=new Node<int>(temp->data);
        tail=head;
    }else{
        tail->next=new Node<int>(temp->data);
        tail=tail->next;
    }
    // cout<<temp->data<<" ";
    if(temp->left!=NULL)
    pendingNodes.push(temp->left);
    if(temp->right!=NULL)
    pendingNodes.push(temp->right);
}
return allheads;
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;

}





/**
 when either stack gets empty its a new level
 when switch stacks print new line
 */

#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int> *> rls_o;
    stack<BinaryTreeNode<int> *> lrs_e;
    int o_e=1;
    if(root==NULL)return;
    rls_o.push(root);
    
    while(!rls_o.empty() || !lrs_e.empty()){//run if either is un-empty
        while(!rls_o.empty()){//odd
            if(rls_o.empty())break;
            BinaryTreeNode<int> * temp=rls_o.top();
            rls_o.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL){lrs_e.push(temp->left);}
            if(temp->right!=NULL){lrs_e.push(temp->right);}
            if(rls_o.empty()){cout<<endl;}
        }
        
        while(!lrs_e.empty()){
            BinaryTreeNode<int> * temp=lrs_e.top();
            lrs_e.pop();
            cout<<temp->data<<" ";
            if(temp->right!=NULL){rls_o.push(temp->right);}
            if(temp->left!=NULL){rls_o.push(temp->left);}
            if(lrs_e.empty()){cout<<endl;}
        }
        o_e++;
    }
}

//int main() {
//    BinaryTreeNode<int>* root = takeInput();
//    cout << (isBalanced(root) ? "true" : "false");
//}

//BinaryTreeNode<int>* takeInput() {
//    int rootData;
//    cin >> rootData;
//    if (rootData == -1) {
//        return NULL;
//    }
//    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
//    queue<BinaryTreeNode<int>*> q;
//    q.push(root);
//    while (!q.empty()) {
//        BinaryTreeNode<int>* currentNode = q.front();
//        q.pop();
//        int leftChild, rightChild;
//
//        cin >> leftChild;
//        if (leftChild != -1) {
//            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
//            currentNode->left = leftNode;
//            q.push(leftNode);
//        }
//
//        cin >> rightChild;
//        if (rightChild != -1) {
//            BinaryTreeNode<int>* rightNode =
//                new BinaryTreeNode<int>(rightChild);
//            currentNode->right = rightNode;
//            q.push(rightNode);
//        }
//    }
//    return root;
//}

BinaryTreeNode<int>* help(int *input,int s,int e){
    if(input==NULL)return NULL;
    if(s>e)return NULL;
    
    int mid=((s+e)/2);
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    root->left=help(input,s,mid-1);
    root->right=help(input,mid+1,e);
    
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    BinaryTreeNode<int>* ans=help(input,0,n-1);
    return ans;
}
void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}
//
//int main() {
//    BinaryTreeNode<int>* root = takeInput();
//    zigZagOrder(root);
//}

/*
 1. If out of 2 nodes only one node is present, return that node.
 2. If both are not present, return -1.**/

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root==NULL) return -1;//EDGE CASE
    if(root->data==a || root->data==b){
        return root->data;//BASE CASE
    }
    int val=root->data;
    int leftlca=-1;
    int rightlca=-1;
    if(!(a>=val && b>=val))
    leftlca=getLCA(root->left, a, b);
    if(!(a<val && b<val))
    rightlca=getLCA(root->right, a, b);
    
    if(leftlca==-1 && rightlca==-1){
        return -1;// not present either side
    }
    if(leftlca==-1){return rightlca;}// present in right subtree
    if(rightlca==-1){return leftlca;}//present in left substree
    
    return root->data;// either in either subtree
    
}
