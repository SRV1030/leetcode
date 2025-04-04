/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int depths[1001]={};
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        if (depths[root->val])
            return depths[root->val];
        return depths[root->val] =
                   1 + max(depth(root->left), depth(root->right));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return root;
        int leftTreeDepth = depth(root->left),
            rightTreeDepth = depth(root->right);
        if (leftTreeDepth == rightTreeDepth)
            return root;
        if (leftTreeDepth > rightTreeDepth)
            return lcaDeepestLeaves(root->left);
        return lcaDeepestLeaves(root->right);
    }
};