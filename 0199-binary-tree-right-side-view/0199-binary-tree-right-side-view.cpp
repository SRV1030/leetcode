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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root){
            queue<TreeNode* > bfsQueue;
            bfsQueue.push(root);
            while(!bfsQueue.empty()){
                int size = bfsQueue.size();
                for (int index = 0; index < size; ++index){
                    TreeNode* node = bfsQueue.front();
                    bfsQueue.pop();
                    if(index == size - 1)
                        result.push_back(node->val);
                    if(node->left)
                        bfsQueue.push(node->left);
                    if(node->right)
                        bfsQueue.push(node->right);
                }
            }
        }
        return result;
    }
};