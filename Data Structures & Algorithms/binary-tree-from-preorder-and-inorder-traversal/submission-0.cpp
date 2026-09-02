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

class Solution {
public:
    TreeNode* sol(int i, int j, int &index,vector<int>& preorder, unordered_map<int,int> &mp )
    {
        if(i>j) return NULL;

        int val=preorder[index];
        index++;
        int mid=mp[val];
        
         TreeNode* root= new  TreeNode(val);

         root->left=sol(i,mid-1,index,preorder,mp);
         root->right=sol(mid+1,j,index,preorder,mp);


         return root;


    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for(int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;
        int index=0;
        return sol(0,preorder.size()-1, index, preorder,mp);
    }
};
