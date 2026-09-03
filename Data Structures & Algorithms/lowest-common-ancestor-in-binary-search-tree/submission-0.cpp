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
    bool check(TreeNode* root, TreeNode* p, vector<TreeNode* > &path)
    {
        if(!root) return false;
        path.push_back(root);

        if(root->val==p->val || check(root->left,p,path) || check(root->right,p,path))
        return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        if(!check(root,p,path1) || !check(root,q,path2)) return NULL;

        int i=0,j=0;

        while(i<path1.size() && j<path2.size() && path1[i]==path2[j])
        i++,j++;

        return path1[i-1];
    }
};
