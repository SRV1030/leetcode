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
    TreeNode* computeTree(string traversal, int& ind, int depth) {
        if (ind >= traversal.size())
            return NULL;
        int prevInd = ind, curr_depth = 0, curr_val = 0;
        while (ind < traversal.size() && traversal[ind] == '-') {
            ++ind;
            ++curr_depth;
        }
        if (curr_depth < depth) {
            ind = prevInd;
            return NULL;
        }
        while (ind < traversal.size() && traversal[ind] != '-') {
            curr_val = curr_val * 10 + (traversal[ind++] - '0');
        }
        TreeNode* root = new TreeNode(curr_val);
        root->left = computeTree(traversal, ind, depth + 1);
        root->right = computeTree(traversal, ind, depth + 1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int ind = 0;
        return computeTree(traversal, ind, 0);
    }
};