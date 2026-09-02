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
    ListNode* merge(ListNode* frst, ListNode* sec)
    {
        ListNode* root= new ListNode(-1);
        ListNode* t=root;

        while(frst && sec)
        {
            if(frst->val<sec->val) t->next=frst, t=frst, frst=frst->next;
            else t->next=sec,t=sec, sec=sec->next;
        }

        if(frst) t->next=frst;
        if(sec) t->next=sec;

        return root->next;
    }
    ListNode* sol(int i, int j, vector<ListNode*>& lists)
    {
       if (i > j) return nullptr; 
        if(i==j) return lists[i];
        int mid=i+(j-i)/2;

          ListNode* frst=sol(i,mid,lists);
            ListNode* sec=sol(mid+1,j,lists);

            return merge(frst,sec);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
      return sol(0,lists.size()-1, lists);
    }
};
