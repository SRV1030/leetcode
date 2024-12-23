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
    int minSwap(vector<int>t){
        vector<pair<int,int>>d;
        for(int i=0;i<t.size();++i)d.push_back({t[i],i});
        sort(begin(d),end(d));
        int c=0;
        for(int i=0;i<t.size();++i){
            if(d[i].second==i) continue;
            else{
                ++c;
                swap(d[i],d[d[i].second]);
                --i;
            }
        }
        return c;
    }
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>t;
            while(n--){
                TreeNode* ele=q.front();
                q.pop();
                t.push_back(ele->val);
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            cnt+=minSwap(t);
        }
        return cnt;
    }
};