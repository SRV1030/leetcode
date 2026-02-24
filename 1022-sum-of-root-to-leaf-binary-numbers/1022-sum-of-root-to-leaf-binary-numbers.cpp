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
    int total = 0;
public:
    void sum(TreeNode* root, int num){
        if(!root)
            return;
        num <<= 1;
        num |= root->val;
        if(!root->left && !root->right)
            total += num;
        sum(root->left, num);
        sum(root->right, num);
    }
    int sumRootToLeaf(TreeNode* root) {
        sum(root, 0);
        return total;
    }
};