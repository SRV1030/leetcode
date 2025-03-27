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
    int postInd;
    int find(int k, vector<int>& in, int l, int h) {
        for (int i = l; i <= h; i++)
            if (in[i] == k)
                return i;
        return -1;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l,
                    int h) {
        if (l > h)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postInd--]);
        int ind = find(root->val, inorder, l, h);
        if (ind != -1) {
            root->right = build(inorder, postorder, ind + 1, h);
            root->left = build(inorder, postorder, l, ind - 1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postInd = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};