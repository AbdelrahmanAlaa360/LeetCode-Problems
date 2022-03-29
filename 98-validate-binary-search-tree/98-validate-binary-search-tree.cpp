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
    long long last = INT_MIN - 1LL;
    bool InOrder(TreeNode* root){
        if(root==NULL)return true;        
        if(!InOrder(root->left))return false;
        if(root->val <= last && last != INT_MIN - 1LL)return false;
        last = root->val;
        if(!InOrder(root->right))return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return InOrder(root);        
    }
};