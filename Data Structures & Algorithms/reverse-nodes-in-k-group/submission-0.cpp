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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* curr=head;
       ListNode* newHead=NULL;
       ListNode* tail=NULL;

       while(curr)
       {
          ListNode* check=curr;
          int c=0;
          while(check && c<k)
          check=check->next, c++;

          if(c<k)
          {
             if(tail) tail->next=curr;
             break;
          }

          ListNode* grpHead=curr;
          ListNode* prev=NULL;
          ListNode* next=NULL;
           c=0;
          while(curr && c<k)
          {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
          }

          if(!newHead) newHead=prev;
          if(tail) tail->next=prev;
          tail=grpHead;


       }
       return newHead;
    }
};
