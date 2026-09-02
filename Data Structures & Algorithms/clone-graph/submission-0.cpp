/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  void sol(Node *node, Node *root,unordered_map<Node*, Node*> &mp )
  {
        mp[node]=root;

        for(auto x: (node->neighbors))
        {

            if(mp.find(x)==mp.end())
            {
                Node* t= new Node(x->val);
                mp[x]=t;
                (t->neighbors).push_back(root);
                sol(x,t,mp);

            }
            else
            ( mp[x]->neighbors).push_back(root);
            
        }

  }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*, Node*> mp;

        Node* root= new Node(node->val);
        
          sol(node, root, mp);

       return root;
        


    }
};
