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
    vector<vector<vector<TreeNode*>>> memory;
    vector<TreeNode*> generateAllUniqueBST(int start, int end){
        if(start > end)
            return {NULL};
        vector<TreeNode*>& allTrees = memory[start][end];
        if(allTrees.empty()){
            for(int node = start; node <= end; node++){
                vector<TreeNode*> leftSubBSTs = generateAllUniqueBST(start, node - 1);
                vector<TreeNode*> rightSubBSTs = generateAllUniqueBST(node + 1, end);
                for(auto& leftSubBST: leftSubBSTs)
                    for(auto& rightSubBST: rightSubBSTs){
                        TreeNode* root = new TreeNode(node);
                        root->left = leftSubBST;
                        root->right = rightSubBST;
                        allTrees.push_back(root);
                    }
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return vector<TreeNode*>();
        memory = vector<vector<vector<TreeNode*>>>(n+1, vector<vector<TreeNode*>>(n+1));
        return generateAllUniqueBST(1, n);
    }
};