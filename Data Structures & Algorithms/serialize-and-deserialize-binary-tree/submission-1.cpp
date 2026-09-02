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
    void serializeTree(TreeNode* root, string &ans)
    {
        if(!root)
        {
            ans.append("#,");
            return ;
        }
        ans.append(to_string(root->val)+",");
        serializeTree(root->left,ans);
        serializeTree(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans="";
        serializeTree(root,ans);
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
    TreeNode* deserializeTree(int &index, vector<string> &nodeList)
    {
           if(nodeList[index]=="#")
           {
             index++;
             return NULL;
           }
           TreeNode* newNode= new TreeNode(stoi(nodeList[index]));
           index++;
           newNode->left=deserializeTree(index,nodeList);
           newNode->right=deserializeTree(index,nodeList);
           return newNode;

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        vector<string> nodeList=splitList(data);

        int index=0;
        return deserializeTree(index,nodeList);


    }
};
