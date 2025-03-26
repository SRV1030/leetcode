/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

public:
int preInd=0;
    int findInorder(int l, int h, int val, vector<int>& inorder) {
        for (int i = l; i <= h; i++)
            if (inorder[i] == val)
                return i;
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int h) {
        if(l>h) return NULL;
        TreeNode *newNode= new TreeNode(preorder[preInd++]);
        int ind=findInorder(l,h,newNode->val,inorder);
        if(ind!=-1){
            newNode->left=build(preorder, inorder, l, ind-1);
            newNode->right=build(preorder, inorder, ind+1,h);
        }
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};