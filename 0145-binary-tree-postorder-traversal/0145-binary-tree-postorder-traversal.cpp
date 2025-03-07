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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        stack<TreeNode*> s;
        s.push(root);
        vector<int> postorder;
        while (!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            postorder.push_back(top->val);
            if (top->left) {
                s.push(top->left);
            }
            if (top->right) {
                s.push(top->right);
            }
        }
        reverse(postorder.begin(), postorder.end());

        return postorder;
    }
};