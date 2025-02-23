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
    TreeNode* computeTree(int preInd, int preEnd, int postInd,
                          vector<int>& preorder,
                          vector<int>& postOrderIndices) {
        if (preInd > preEnd)
            return NULL;
        if (preInd == preEnd)
            return new TreeNode(preorder[preInd]);
        int leftRoot = preorder[preInd + 1],
            leftTreeSize = postOrderIndices[leftRoot] - postInd + 1;
        TreeNode* root = new TreeNode(preorder[preInd]);
        root->left = computeTree(preInd + 1, preInd + leftTreeSize, postInd,
                                 preorder, postOrderIndices);
        root->right =
            computeTree(preInd + leftTreeSize + 1, preEnd,
                        postInd + leftTreeSize, preorder, postOrderIndices);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int sizeTree = preorder.size();
        vector<int> postOrderIndices(sizeTree+1);
        for (int i = 0; i < sizeTree; ++i)
            postOrderIndices[postorder[i]] = i;
        return computeTree(0, sizeTree - 1, 0, preorder, postOrderIndices);
    }
};