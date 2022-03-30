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
    vector<double> averageOfLevels(TreeNode* root) {        
        vector<double>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            double tot = 0;
            int numOfNodes = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                tot += curr->val;
                numOfNodes++;
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                q.pop();
            }
            ans.push_back(tot / numOfNodes);
        }
        return ans;        
    }
};