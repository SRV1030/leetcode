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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        vector<vector<int>>val;
        queue<TreeNode*>q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                if(lvl%2!=0)v.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            val.push_back(v);
            ++lvl;
        }

        q.push(root);
        lvl=0;
        while(!q.empty()){
            int n=q.size();
            int x=val[lvl].size()-1;
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                if(lvl%2!=0)t->val=val[lvl][x--];
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ++lvl;
        }
        return root;
    }
};