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
    enum State{
        VISIBLE,
        INVISIBLE,
        CAMERA
    };
    int minCamera;
public:
    State checkVisibility(TreeNode* root){
        if(!root)
            return VISIBLE;
        State leftTreeVisibility = checkVisibility(root->left), rightTreeVisibility = checkVisibility(root->right);
        if(leftTreeVisibility == INVISIBLE || rightTreeVisibility == INVISIBLE){
            ++minCamera;
            return CAMERA;
        }
        return leftTreeVisibility == CAMERA || rightTreeVisibility == CAMERA ? VISIBLE : INVISIBLE;
    }
    int minCameraCover(TreeNode* root) {
        minCamera = 0;
        return checkVisibility(root) == INVISIBLE ? minCamera + 1 : minCamera;
    }
};