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
    bool balance = true;
    int height(TreeNode* root){
        if(!root || !balance) return 0;
        int hl=height(root->left),hr=height(root->right);
        if(abs(hl-hr)>1) balance=false;
        return 1+max(hl,hr);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return balance;
    }
};