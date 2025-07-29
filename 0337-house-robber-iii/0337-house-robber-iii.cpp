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
    pair<int, int> gatherMoney(TreeNode* root){
        if(!root)
            return {0, 0};
        if(!root->left && !root->right)
            return {root->val, 0};
        pair<int, int> leftGather = gatherMoney(root->left);
        pair<int, int> rightGather = gatherMoney(root->right);
        return {root->val + leftGather.second + rightGather.second, max(leftGather.first, leftGather.second) + max(rightGather.first, rightGather.second)};
    }
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        pair<int, int> moneyGathered = gatherMoney(root);
        return (max(moneyGathered.first, moneyGathered.second));
    }
};