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
    stack<TreeNode*>nodeStack;
    void fillStack(TreeNode* root){
        for(;root;root=root->left)nodeStack.push(root);
    }
public:
    BSTIterator(TreeNode* root) {
        fillStack(root);
    }
    
    int next() {
        TreeNode* next = nodeStack.top();
        nodeStack.pop();
        fillStack(next->right);
        return next->val;
    }
    
    bool hasNext() {
        return !nodeStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */