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
    ListNode* reverse(ListNode* head) {
        ListNode* current = head, *next = nullptr, *prev = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverse(l1), *r2 = reverse(l2);
        ListNode* sum = new ListNode(0), *sumHead = sum;
        int carry = 0;

        // \U0001f539 Main loop: process both lists
        while (r1 || r2 || carry) {
            int value = carry;  // start with carry

            // \U0001f539 Add node values if present
            if (r1) {
                value += r1->val;
                r1 = r1->next;
            }
            if (r2) {
                value += r2->val;
                r2 = r2->next;
            }

            // \U0001f539 fix: compute digit = value % 10, carry = value / 10
            sumHead->next = new ListNode(value % 10);
            carry = value / 10;

            sumHead = sumHead->next;
        }

        // \U0001f539 reverse result before returning
        ListNode* result = reverse(sum->next);
        return result;
    }
};
