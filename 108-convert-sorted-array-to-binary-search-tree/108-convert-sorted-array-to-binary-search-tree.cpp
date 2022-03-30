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
    TreeNode* insertBstNode(vector<int>&nums, int start, int end){
        if(start > end)return NULL;
        int mid = (start + end) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = insertBstNode(nums, start, mid - 1);
        newNode->right = insertBstNode(nums, mid + 1, end);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {        
        return insertBstNode(nums, 0, nums.size() - 1);
    }
};