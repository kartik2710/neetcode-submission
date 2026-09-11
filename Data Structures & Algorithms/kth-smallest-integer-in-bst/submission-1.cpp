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
    int solve(TreeNode* root, int k, int &counter)
    {
        if(!root) return -1;

        int left=solve(root->left,k,counter);
        
        if(left!=-1) return left;
        counter++;

        if(k==counter)
        return root->val;

      

        return solve(root->right,k,counter);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0,counter=0;
        return solve(root,k,counter);
       

    }
};
