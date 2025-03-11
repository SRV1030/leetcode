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
    int maxPath = INT_MIN;
    int pathSum(TreeNode* root){
        if(!root) return 0;
        int leftSum = max(0,pathSum(root->left)),rightSum=max(0,pathSum(root->right));
        int currentSum = root->val+leftSum+rightSum;
        if(maxPath<currentSum)maxPath=currentSum;
        return root->val+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxPath;
    }
};