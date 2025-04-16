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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        unsigned long long mx=0;
        deque<pair<TreeNode*,unsigned long long>>q;
        q.push_back({root,1});
        while(!q.empty()){
            int n=q.size();
            mx=max(mx,q.back().second-q.front().second+1);
            while(n--){
                auto f = q.front();
                q.pop_front();
                if(f.first->left) q.push_back({f.first->left,2*f.second});
                if(f.first->right) q.push_back({f.first->right,2*f.second+1});
            }
        }
        return mx;
    }
};