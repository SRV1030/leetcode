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
class Solution {
    int len = 0;
    ListNode* root;
public:
    Solution(ListNode* head) {
        root = head;
        while(head){
            ++len;
            head = head->next;
        }
    }
    
    int getRandom() {
        int rIndex = rand() % len;
        ListNode* head = root;
        while(rIndex--){
            head = head->next;
        }
        return head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */