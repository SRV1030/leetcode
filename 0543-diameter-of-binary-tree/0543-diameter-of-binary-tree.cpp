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
    int d=0;
    int height(TreeNode* root){
        if(!root) return 0;
        int hl = height(root->left), hr = height(root->right);
        if(hl+hr>d)d=hl+hr;
        return 1+max(hl,hr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return d;
    }
};