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
    TreeNode *first, *second, *prev = new TreeNode(INT_MIN);
public:
    void solve(TreeNode* root){
        if(!root)
            return;
        solve(root->left);
        if(prev->val > root->val){
            if(!first){
                first = prev;
                second = root;
            }
            else
                second = root;
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        solve(root);
        if(!first || !second)
            return;
        swap(first->val , second->val);
    }
};