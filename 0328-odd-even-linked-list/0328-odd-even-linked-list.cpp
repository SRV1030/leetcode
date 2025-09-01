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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* odd = head, *even = head->next, *current = even, *previous = odd;
        while(current && current->next && previous && previous->next){
            previous->next = current->next;
            previous = current->next;
            current->next = previous->next;
            current = previous->next;
        }
        previous->next = even;
        return odd;
    }
};