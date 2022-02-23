/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* solve(ListNode* l1,ListNode* l2,int &carry)
    {
        if(l1==NULL && l2==NULL){
            return NULL;
        }

        ListNode* node=solve(l1->next,l2->next,carry);
        int val=carry+l1->val+l2->val;
        ListNode* head=insertAtHead(node,val%10);
        carry=val/10;
        return head;
    }

    ListNode* padList(ListNode* head,int x)
    {
       for(int i=0;i<x;i++)
       {
           head=insertAtHead(head,0);
       }

      return head;
    }

    ListNode* insertAtHead(ListNode* head,int data)
    {
        ListNode* node=new ListNode(data);
        if(head!=NULL){
            node->next=head;
        }
        return node;
    }


    int length(ListNode* head)
    {
        if(!head)return 0;
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l11=length(l1);
        int l22=length(l2);
        cout<<l11<<" "<<l22;
        if(l11>l22)
            l2=padList(l2,l11-l22);
        if(l22>l11)
            l1=padList(l1,l22-l11);
        int carry=0;
        ListNode* head=solve(l1,l2,carry);

        if(carry!=0)
            head=insertAtHead(head,carry);
        return head;
    }
};
