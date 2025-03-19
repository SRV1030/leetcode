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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int f=1;
        while(!q.empty()){
            int n=q.size();
            vector<int>t;
            while(n--){
                TreeNode* cur=q.front();
                q.pop();
                if(f)t.push_back(cur->val);
                else t.insert(t.begin(),cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            ans.push_back(t);
            f^=1;
        }
        return ans;
    }
};