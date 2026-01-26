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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int size = 1;
        ListNode* tail = head;
        while(tail->next && size++)
            tail = tail->next;
        tail->next = head;
        k %= size;
        if(k){
            k = size - k;
            while(k--)
                tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};