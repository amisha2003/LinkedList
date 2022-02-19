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

Node* returnKthToLast1(Node* head,int k,int& i)     //Recursive  {O(1) time complexity && O(N) space}
{
    if(head==NULL)
        return NULL;

    Node* node=returnKthToLast1(head->next,k,i);
    i++;
    if(i==k){
        return head;
    }
    return node;

}

Node* returnKthToLast2(Node* head, int k)    //Iterative {O(N) time complexity && O(1) space}
{
    Node* pr1=head;
    Node* pr2=head;

    while(k)                  //Move pr1 k nodes into the list;
    {
        if(pr1==NULL)
            return NULL; //Out of Bound
        pr1=pr1->next;
        k--;
    }
    while(pr1!=NULL)         // Move them at the same space. When pr1 hits the end, p2 will be at the right element.
    {
        pr2=pr2->next;
        pr1=pr1->next;
    }
    return pr2;
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
    int i=0;
    //Node* ans=returnKthToLast1(head,1,i);  //Recursive
    Node* ans=returnKthToLast2(head,3);     //Iterative
    cout<<ans->data<<endl;

}
