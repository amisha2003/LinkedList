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

 Node* partition(Node* head, int x) {
        if(!head || !head->next)return head;
        Node* curr=head;
        Node* answer=NULL;
        Node* start=NULL;
        Node* half=NULL;
        Node* ans=NULL;

        while(curr!=NULL)
        {
            if(curr->data<x)
            {
                if(answer==NULL){
                    answer=curr;
                    ans=answer;
                }
                else{
                ans->next=curr;
                ans=ans->next;
                }
            }
            else
            {
                if(start==NULL){
                    start=curr;
                    half=start;
                }
                else
                {
                    half->next=curr;
                    half=half->next;
                }

            }
            curr=curr->next;
        }
        if(half!=NULL)
          half->next=NULL;
        if(ans==NULL)
            return start;
        if(start==NULL)
            return answer;

        if(start!=NULL)
          ans->next=start;

        return answer;
}

int main()
{
    Node* head=NULL;
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,2);
    insertNode(head,5);
    insertNode(head,1);
    insertNode(head,4);
    display(head);
    Node* node=partition(head,3);
    display(node);

}
