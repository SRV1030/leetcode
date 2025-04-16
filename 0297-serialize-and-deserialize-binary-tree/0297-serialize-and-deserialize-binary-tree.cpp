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
    string encodedString(TreeNode* root){
        if(!root) return ",n";
        string res = ","+to_string(root->val);
        res+=encodedString(root->left);
        res+=encodedString(root->right);
        return res;
    }
    string serialize(TreeNode* root) {
        string res = encodedString(root);
        return res.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* decodedString(stringstream &str){
        string val;
        getline(str,val,',');
        if(val=="n") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = decodedString(str);
        root->right = decodedString(str);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream str(data);
        return decodedString(str);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));