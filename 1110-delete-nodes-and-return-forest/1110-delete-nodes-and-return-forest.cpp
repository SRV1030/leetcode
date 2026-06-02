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
    set<int> st;
    vector<TreeNode*> res;
public:
    TreeNode* dfs(TreeNode* root, bool isRoot){
        if(!root)
            return root;
        bool deleted = st.count(root->val);
        if(isRoot & !deleted)
            res.push_back(root);
        root->left = dfs(root->left, deleted);
        root->right = dfs(root->right, deleted);
        return deleted ? NULL : root;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto& node : to_delete)
            st.insert(node);
        dfs(root, true);
        return res;
    }
};