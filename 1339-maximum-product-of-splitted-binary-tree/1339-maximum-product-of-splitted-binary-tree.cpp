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
    long long result = 0, total = 0, MOD = 1e9 + 7;
    int childSumRoot(TreeNode* root){
        if(!root)
            return 0;
        int left = childSumRoot(root->left) % MOD, right = childSumRoot(root->right) % MOD;
        root->val = (root->val + left + right) % MOD;
        return root->val;
    }
    void findMaxProduct(TreeNode* root){
        if(!root)
            return;
        findMaxProduct(root->left);
        findMaxProduct(root->right);
        result = max(result, root->val * (total - root->val));
    }
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        total = childSumRoot(root);
        findMaxProduct(root);
        return result % MOD;
    }
};