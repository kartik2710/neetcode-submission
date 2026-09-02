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
ListNode* reverse(ListNode* l)
{
    ListNode* curr=l, *next=NULL, *prev=NULL;

    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reverse(l1);
        // l2=reverse(l2);
        int carry=0,sum=0;
     

    ListNode* root= new ListNode(-1);
    ListNode* t=root;
        while(l1 || l2)
        {
            sum=carry;
            if(l1) sum+=l1->val, l1=l1->next;
            if(l2) sum+=l2->val, l2=l2->next; 

             ListNode* newNode= new ListNode(sum%10);
           t->next=newNode;
           t=newNode;

            carry=sum/10;





        }
        if(carry)
        {
            ListNode* newNode= new ListNode(carry);
           t->next=newNode;
           t=newNode;
        }

        return root->next;

    }
};
