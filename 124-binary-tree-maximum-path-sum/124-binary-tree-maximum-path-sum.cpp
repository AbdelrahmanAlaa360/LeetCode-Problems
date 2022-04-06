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
    int ans = INT_MIN;
    int traverse(TreeNode* root){
        if(root == NULL)return 0;
        int left = max(0, traverse(root->left));
        int right = max(0, traverse(root->right));
        int sum = root->val + left + right;
        ans = max(ans, sum);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;
    }
};