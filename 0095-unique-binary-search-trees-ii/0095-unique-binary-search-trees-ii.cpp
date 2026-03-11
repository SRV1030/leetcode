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
    vector<vector<vector<TreeNode*>>> memo;
public:
    vector<TreeNode*> generate(int start, int end){
        if(start > end)
            return {NULL};
        
        vector<TreeNode*>& allPos = memo[start][end];
        if(allPos.empty()){
            for(int node = start; node <= end; ++node){
                vector<TreeNode*> lefts = generate(start, node - 1);
                vector<TreeNode*> rights = generate(node + 1, end);
                for(auto& left : lefts){
                    for(auto& right : rights){
                        TreeNode* root = new TreeNode(node);
                        root->left = left;
                        root->right = right;
                        allPos.push_back(root);
                    }
                }
            }
        }
        return allPos;
    }
    vector<TreeNode*> generateTrees(int n) {
        memo = vector<vector<vector<TreeNode*>>> (n + 1, vector<vector<TreeNode*>>(n + 1));
        return generate(1 , n);
    }
};