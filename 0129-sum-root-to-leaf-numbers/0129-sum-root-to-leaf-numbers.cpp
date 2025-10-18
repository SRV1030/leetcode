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
    int sum = 0;
public:
    void calSum(TreeNode* root, int num){
        if(!root)
            return;
        num = num * 10 + root->val;
        if(!root->left && !root->right){
            sum += num;
        }
        calSum(root->left, num);
        calSum(root->right, num);
    }
    int sumNumbers(TreeNode* root) {
        if(root){
            calSum(root, 0);
        }
        return sum;
    }
};