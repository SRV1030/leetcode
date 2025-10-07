class Solution {
public:
    int ans=-1;
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return -1;
        kthSmallest(root->left,k);
        if(!--k) {
            ans=root->val;   
            return ans;
        }
        kthSmallest(root->right,k);
        return ans;
    }
};