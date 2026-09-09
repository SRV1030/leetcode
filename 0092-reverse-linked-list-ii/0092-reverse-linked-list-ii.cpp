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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
            return head;
        ListNode* cur = head, *leftStart = NULL, *rightEnd;
        for(int ind = 1; ind < left && cur; ++ind){
            leftStart = cur;
            cur = cur->next;
        }
        rightEnd = cur;
        ListNode *prev = NULL, *next;
        for(int ind = left; ind <= right && cur; ++ind){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if(leftStart)
            leftStart->next = prev;
        else
            head = prev;

        rightEnd->next = cur;
        return head;
    }
};