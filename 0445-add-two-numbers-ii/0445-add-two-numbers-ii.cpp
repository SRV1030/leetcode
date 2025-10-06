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
    ListNode* reverse(ListNode* head){
        ListNode* current = head, *next = NULL, *prev = NULL;
        while(current){
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
        while(r1 && r2){
            int value = (r1->val + r2->val + carry);
            sumHead->next = new ListNode(value % 10);
            carry = value / 10;
            r1= r1->next;
            r2 = r2->next;
            sumHead = sumHead->next;
        }
        while(r1){
            int value = (r1->val + carry);
            sumHead->next = new ListNode(value % 10);
            carry = value / 10;
            r1= r1->next;
            sumHead = sumHead->next;
        }
        while(r2){
            int value = (r2->val + carry);
            sumHead->next = new ListNode(value % 10);
            carry = value / 10;
            r2= r2->next;
            sumHead = sumHead->next;
        }
        if(carry){
            sumHead->next = new ListNode(carry);
        }
        ListNode* reslt = sum->next;
        return reverse(reslt);
    }
};