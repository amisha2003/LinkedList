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
    cout<<"NULL";
    cout<<endl;
    return;
}

void deleteMiddleNode(Node* &head)
{
    if(!head || !head->next || !head->next->next)return ;
    Node* p1=head;
    Node* p2=head;
    Node* prev=NULL;
    while(p2->next!=NULL && p2->next->next!=NULL)
    {
        prev=p1;
        p1=p1->next;
        p2=p2->next->next;
    }
    prev->next=p1->next;
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
    deleteMiddleNode(head);
    display(head);

}
