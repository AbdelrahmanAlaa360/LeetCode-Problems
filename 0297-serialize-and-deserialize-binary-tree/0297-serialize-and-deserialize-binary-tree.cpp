/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        getStream(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return buildTree(in);
    }
    
    void getStream(TreeNode* root, ostringstream &out) {
        if(root == NULL) {
            out << "# ";
            return;
        }
        out << root->val << ' '; 
        getStream(root->left, out);
        getStream(root->right, out);
    }

    TreeNode* buildTree(istringstream &in) {
        string val;
        in >> val;
        if(val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(in);
        root->right = buildTree(in);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));