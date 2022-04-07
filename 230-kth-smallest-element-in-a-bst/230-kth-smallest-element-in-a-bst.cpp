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
    /*int ans = 0, k2;
    void InorderTraversal(TreeNode* root){         
        if(root == NULL)return;
        InorderTraversal(root->left);
        k2--;
        if(k2 == 0) ans = root->val;
        InorderTraversal(root->right);        
    }*/
    vector<int>v;
    void InorderTraversal(TreeNode* root, int k){         
        if(root == NULL){                        
            return;
        }
        InorderTraversal(root->left, k);        
        v.push_back(root->val);
        InorderTraversal(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {                
        InorderTraversal(root, k);
        return v[k - 1];
        
        /*k2 = k;
        InorderTraversal(root);
        return ans;*/
    }    
};