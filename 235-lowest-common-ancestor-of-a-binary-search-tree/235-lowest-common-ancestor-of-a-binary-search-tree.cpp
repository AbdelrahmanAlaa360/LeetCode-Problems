/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA(TreeNode* root, int p, int q){
        if(root == NULL)return root;
        if(p > root->val && q > root->val)
            return LCA(root->right, p, q);
        else if(p < root->val && q < root->val)
            return LCA(root->left, p, q);
        return root;    
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p->val, q->val);
    }
};