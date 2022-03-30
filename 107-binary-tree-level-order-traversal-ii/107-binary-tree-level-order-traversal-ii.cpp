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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){        
            vector<int>level;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                q.pop();
            }
            ans.push_back(level);
        }
        for(int i = 0; i < ans.size() / 2; i++){
            swap(ans[i], ans[ans.size() - i - 1]);
        }
        return ans;
    }
};