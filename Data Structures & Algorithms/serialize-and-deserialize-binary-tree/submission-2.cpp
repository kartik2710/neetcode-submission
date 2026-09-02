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
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        ans.append(to_string(root->val)+",");

        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            if(node->left) 
             q.push(node->left),ans.append(to_string(node->left->val)+",");
            else
             ans.append("#,");

            if(node->right) 
             q.push(node->right),ans.append(to_string(node->right->val)+",");
            else
             ans.append("#,");

        }
        cout<<ans<<endl;
        return ans;

    }

    vector<string> splitList(string data)
    {
        vector<string> nodeList;
        string temp="";
        for(auto x: data)
        {
            if(x==',')
            {
                nodeList.push_back(temp);
                temp="";
            }
            else
            temp+=x;
        }

        return nodeList;
    }
   
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        vector<string> nodeList=splitList(data);

       
        TreeNode* newNode= new TreeNode(stoi(nodeList[0]));
        queue<TreeNode*> q;
        q.push(newNode);
        int index=1;
        while(!q.empty())
        {
           TreeNode* node=q.front();
           q.pop();

           if(nodeList[index]=="#")
             node->left=NULL;
            else
            {
                TreeNode* temp= new TreeNode(stoi(nodeList[index]));
                node->left=temp;
                q.push(temp);
            }
            index++;
             if(nodeList[index]=="#")
             node->right=NULL;
            else
            {
                TreeNode* temp= new TreeNode(stoi(nodeList[index]));
                node->right=temp;
                q.push(temp);
            }
            index++;




        }

        return newNode;


    }
};
