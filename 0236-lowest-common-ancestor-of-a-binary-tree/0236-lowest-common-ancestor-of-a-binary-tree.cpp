/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        if(root==p || root==q) return root;
        TreeNode *la = lowestCommonAncestor(root->left, p, q),
                 *ra = lowestCommonAncestor(root->right, p, q);
        return la && ra ? root : la ? la : ra;
    }
};