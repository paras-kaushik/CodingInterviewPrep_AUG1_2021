
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int findNode(Node *head, int n){
    int index=0;
    if(head==NULL) return -1;
    while(head->next!=NULL){
        if(head->data==n){
            return index;
        }
        head=head->next;
        index++;
    }
    return -1;
}
int length(Node *head) {

  Node* temp=head;
  
  int l=0;
  while(temp!=NULL){l++;temp=temp->next;}
  return l;
}
Node *appendLastNToFirst(Node *head, int n)
{
    if(head==NULL) return NULL;
    int l=length(head);
    int r=(l-n);
    Node* target=head;
    int t=0;
    while(t<(r)){
        target=target->next;
        t++;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    cout<<head->data<<" "<<target->data<<""<<tail->next<<endl;
    return NULL;
}

Node *removeDuplicates(Node *head)
{
    if(head==NULL)return NULL;
    Node* i=head;
    Node* j=head;
    //Node* pi=NULL;
    
    while (j!=NULL) {
        while (j!=NULL && j->data==i->data) {
            j=j->next;
        }
        Node* temp=i->next;
        delete temp;
        i->next=j;
        
        if(i!=NULL) i=i->next;
        
        if(j!=NULL) j=j->next;
    }
    return head;
}
#include<utility>
pair<Node*, Node*> midNode(Node* head){
    if(head==NULL || head->next==NULL){
        return make_pair(head, head);
    }
    Node* s=head;
    Node* ps=NULL;
    Node* f=head;
    while (s!=NULL && f!=NULL && f->next!=NULL && f->next->next!=NULL) {
        ps=s;
        s=s->next;
        f=f->next->next;
    }
    return make_pair(ps,s);
}
pair<Node*, Node*> rev(Node* head){
    if(head==NULL || head->next==NULL){
        return make_pair(head, head);
    }
    pair<Node*, Node*> ht=rev(head->next);
    
    Node* newtail=head;
    newtail->next=ht.second->next;// small tail ka next assigned to newtail next
    ht.second->next=newtail;
    head=ht.first;
    return make_pair(head, newtail);
    
}
void print(Node* head){
    if(head==NULL)return;
    
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
    cout<<endl;
}
Node *reverseLinkedListRec(Node *head)
{
    return rev(head).first;
}

bool isPalindrome(Node *head)
{   if(head==NULL || head->next==NULL)return true;
    pair<Node*, Node*> mids=midNode(head);
    Node* pm=mids.first;
    Node* m=mids.second;
    pm->next=NULL;
    Node* sec_rev=rev(m).first;
    bool ans=true;
    while(sec_rev!=NULL  && head!=NULL){
        if(sec_rev->data!=head->data){
            return false;
        }
    }
    return ans;
}
//In the given linked list, you need to delete N nodes after every M nodes.

Node *skipMdeleteN(Node *head, int M, int N)
{
    return NULL;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNode(head, val) << endl;
    }
}
