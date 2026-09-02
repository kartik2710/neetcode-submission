/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node *> mp;
        
         Node* root= new  Node(-1);
         Node *follow=root;
         Node *p=head;
    
         while(p)
         {
           
              Node* t= new  Node(p->val);
              follow->next=t;
              follow=t;
              mp[p]=t;
               p=p->next;
         }

         p=head;
         while(p)
         {
            if(p->random)
            mp[p]->random=mp[p->random];
            p=p->next;
         }

         

         return root->next;
    }
};
