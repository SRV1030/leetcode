/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> childToParentMap;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while(!bfsQueue.empty()){
            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();
            if(node->left){
                childToParentMap[node->left->val] = node;
                bfsQueue.push(node->left);
            }
            if(node->right){
                childToParentMap[node->right->val] = node;
                bfsQueue.push(node->right);
            }
        }
        bfsQueue.push(target);
        unordered_set<int> seenNodes;
        while(k-- && !bfsQueue.empty()){
            int loopSize = bfsQueue.size();
            while(loopSize--){
                TreeNode* node= bfsQueue.front();
                bfsQueue.pop();
                seenNodes.insert(node->val);
                if(node->left && !seenNodes.count(node->left->val))
                    bfsQueue.push(node->left);
                if(node->right && !seenNodes.count(node->right->val))
                    bfsQueue.push(node->right);
                if(childToParentMap.count(node->val)){
                    TreeNode* parent = childToParentMap[node->val];
                    if(!seenNodes.count(parent->val))
                        bfsQueue.push(parent);
                }
            }
        }
        vector<int> distanceKNodes;
        while(!bfsQueue.empty()){
            distanceKNodes.push_back(bfsQueue.front()->val);
            bfsQueue.pop();
        }
        return distanceKNodes;
    }
};