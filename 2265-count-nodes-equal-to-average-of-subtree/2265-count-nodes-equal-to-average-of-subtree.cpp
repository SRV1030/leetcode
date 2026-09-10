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
    int count = 0;
public:
    pair<int, int> solve(TreeNode* root){
        if(!root)
            return {0, 0};
        auto [ls , lc] = solve(root->left);
        auto [rs , rc] = solve(root->right);
        if(root->val == (ls + rs + root->val) / (lc + rc + 1))
            ++count;
        return {(ls + rs + root->val) , (lc + rc + 1)};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};