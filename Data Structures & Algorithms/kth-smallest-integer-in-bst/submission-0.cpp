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
    int sol(TreeNode* root, int k, int &c)
    {
        if(!root) return -1;

        int left=sol(root->left,k,c);
        if(left!=-1) return left;
        c++;
        if(c==k) return root->val;
        return sol(root->right,k,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        return sol(root,k,c);
    }
};
