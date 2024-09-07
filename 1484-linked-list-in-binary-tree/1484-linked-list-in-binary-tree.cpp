/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool preorder(ListNode* head,TreeNode* root){
        if(!head) return true;
        if(!root) return false;
        bool check = false;
        if(head->val==root->val)check = check || preorder(head->next,root->left) || preorder(head->next,root->right);
        return check;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        bool result = preorder(head,root);
        if(result) return true;
        result |= isSubPath(head,root->left);
        if(result) return true;
        result |= isSubPath(head,root->right);
        return result;
    }
};