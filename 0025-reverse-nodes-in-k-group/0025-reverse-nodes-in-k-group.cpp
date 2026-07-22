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
    int getLengthOfListNode(ListNode* head){
        int length = 0;
        while(head){
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* reverseKGroupRecursively(ListNode* head, int k, int remainingNodes){
        if(!head || remainingNodes < k)
            return head;
        ListNode* current = head, *previous = NULL, *next = NULL;
        int loopSize = k;
        while(loopSize--){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        remainingNodes -= k;
        if(next) 
            head->next = reverseKGroupRecursively(next, k, remainingNodes);
        return previous;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        return reverseKGroupRecursively(head, k, getLengthOfListNode(head));
    }
};