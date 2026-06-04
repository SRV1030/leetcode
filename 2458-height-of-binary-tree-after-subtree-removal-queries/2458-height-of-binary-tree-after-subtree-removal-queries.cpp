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
    int ht[100001] = {};
    int mx = 0;
public:
    void preorder(TreeNode* root, int depth, int leftToRight){
        if(!root)
            return;
        ht[root->val] = max(ht[root->val], mx);
        mx = max(mx, depth);
        if(leftToRight){
            preorder(root->left, depth + 1, leftToRight);
            preorder(root->right, depth + 1, leftToRight);
        }
        else{
            preorder(root->right, depth + 1, leftToRight);
            preorder(root->left, depth + 1, leftToRight);
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        preorder(root, 0, true);
        mx = 0;
        preorder(root, 0, false);
        vector<int> res;
        for(auto& qr : queries)
            res.push_back(ht[qr]);
        return res;
    }
};