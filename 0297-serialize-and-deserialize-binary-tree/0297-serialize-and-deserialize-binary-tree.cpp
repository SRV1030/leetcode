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
    string encodedString(TreeNode* root){
        if(!root)
            return ",n";
        string ls = encodedString(root->left), rs = encodedString(root->right);
        return "," + to_string(root->val) + ls + rs;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encodedString(root).substr(1);
    }

    TreeNode* decodedString(stringstream &data){
        string val;
        getline(data, val ,',');
        if(val == "n")
            return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = decodedString(data);
        node->right = decodedString(data);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream str(data);
        return decodedString(str);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));