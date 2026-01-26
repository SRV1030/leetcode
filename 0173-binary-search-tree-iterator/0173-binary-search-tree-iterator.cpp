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
class BSTIterator {
    vector<int> data;
    int index;
public:
    void fillData(TreeNode* root){
        if(!root)
            return;
        fillData(root->left);
        data.push_back(root->val);
        fillData(root->right);
    }
    BSTIterator(TreeNode* root) {
        fillData(root);
        index = 0;
    }
    
    int next() {
        if(hasNext())
            return data[index++];
        return -1;
    }
    
    bool hasNext() {
        return index < data.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */