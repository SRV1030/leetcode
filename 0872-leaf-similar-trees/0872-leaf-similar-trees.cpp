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
    
    void inorder(vector<int> &a1,TreeNode* root1){
        if(!root1)return;
        inorder(a1,root1->left);
        if(!root1->left && !root1->right)a1.push_back(root1->val);
        inorder(a1,root1->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 && !root2) return false;
        vector<int>v1,v2;
        inorder(v1,root1);
        inorder(v2,root2);
        return v1==v2;
    }
};