/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();

            if(t) s.append(to_string(t->val)+",");
            else s.append("#,");

            if(t)
            {
                q.push(t->left);
                q.push(t->right);
            }
        }
     cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        
        stringstream s(data);

        string str;

        getline(s,str,',');

        TreeNode * root= new TreeNode (stoi(str));

         queue<TreeNode *> q;
         q.push(root);

        while(!q.empty())
        {
            TreeNode *t=q.front();
            q.pop();

            getline(s,str,',');

            if(str=="#") t->left=NULL;
            else
            {
                TreeNode * p= new TreeNode (stoi(str));
                t->left=p;
                q.push(p);
            }

            getline(s,str,',');

            if(str=="#") t->right=NULL;
            else
            {
                TreeNode * p= new TreeNode (stoi(str));
                t->right=p;
                q.push(p);
            }

        }

        return root;

    }
};
