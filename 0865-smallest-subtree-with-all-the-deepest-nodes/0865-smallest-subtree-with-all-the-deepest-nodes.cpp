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
    TreeNode* lca;
    int maxDist = -1;
public: 
    int getMax(TreeNode* root, int distance){
        maxDist = max(distance, maxDist);
        if(!root)
            return distance;
        int left = getMax(root->left, distance + 1), right = getMax(root->right, distance + 1);
        if(left == maxDist && right == maxDist)
            lca = root;
        return max(left, right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return root;
        getMax(root, 0);
        return lca;
    }
};