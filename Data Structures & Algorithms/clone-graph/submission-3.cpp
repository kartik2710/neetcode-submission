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
    void dfs(Node *node,unordered_map<Node* ,Node *> &mp )
    {
        for(auto x: (node-> neighbors))
        {
            if(mp.find(x)==mp.end())
            {
                 Node *t= new Node(x->val);
                 mp[x]=t;
                 dfs(x,mp);

            }

            (mp[x]->neighbors).push_back(mp[node]);
        }
    }
    Node* cloneGraph(Node* node) 
    {
        if(!node) return node;

       Node *root= new Node(node->val);
        unordered_map<Node* ,Node *> mp;
        mp[node]=root;

        queue<Node *> q;
        q.push(node);

        while(!q.empty())
        {
            Node *lol=q.front();
            q.pop();

             for(auto x: (lol-> neighbors))
           {
              if(mp.find(x)==mp.end())
              {
                 Node *t= new Node(x->val);
                 mp[x]=t;
                 dfs(x,mp);

               }

            (mp[x]->neighbors).push_back(mp[lol]);
           }
        }

        return root;



    }
};