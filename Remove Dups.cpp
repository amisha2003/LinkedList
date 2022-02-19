#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
    Node* next;
    int data;
      Node(int val){
         data=val;
        next=NULL;
      }
};

void insertNode(Node* &head,int val)
{
    Node* node=new Node(val);
    if(head==NULL){
        head=node;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;
    return;
}

void display(Node* head)
{
    if(!head )return;
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NUL";
    return;
}



void removeDuplicates(Node* start)
{
    unordered_set<int> seen;
    Node* curr = start;
    Node* prev = NULL;
    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
        prev->next = curr->next;
        delete (curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}
int main()
{
    Node* head=NULL;
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,2);
    insertNode(head,5);
    insertNode(head,1);
    insertNode(head,3);
     display(head);
    removeDuplicates(head);
    display(head);
}
