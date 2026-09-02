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
ListNode* reverse(ListNode *node)
{
   ListNode *curr=node, *prev=NULL, *next=NULL;
   while(curr)
   {
    cout<<curr->val<<"..";
     next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
   }

   return prev;
}
    void reorderList(ListNode* head) {
        if(!head) return ;
        if(!head->next) return ;

        ListNode* fast=head, *slow=head;

        while(fast && fast->next && fast->next->next)

        cout<<".",slow=slow->next, fast=fast->next->next;


   
        ListNode * newNode=slow->next;
        slow->next=NULL;
        newNode=reverse(newNode);

        ListNode *root= new ListNode(-1);
        ListNode *t=root;

        while(head || newNode)
        {
             t->next=head;
             t=head;
             head=head->next;

             if(newNode)
             {
                t->next=newNode;
                t=newNode;
                newNode=newNode->next;
             }
        }


        ListNode * ans=root;
        // while(root)
        // cout<<root->val<<".", root=root->next;



       


    }
};
