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
    int maxDepth(TreeNode* root) {  
        if(root == NULL)return 0;
        queue<TreeNode*>q;        
        q.push(root);
        int cnt = 0;
        while(!q.empty()){            
            int sz = q.size();            
            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                q.pop();
            }
            cnt++;
        }
        return cnt;
        
    
        /*if(root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);*/        
    }
};