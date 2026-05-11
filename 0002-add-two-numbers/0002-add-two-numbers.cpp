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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sumHead = new ListNode(0), *sum = sumHead;
        int c = 0;
        while(l1 || l2){
            if(l1 && l2){
                int val = l1->val + l2->val + c;
                sum->next = new ListNode(val % 10);
                c = val / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                int val = l1->val + c;
                sum->next = new ListNode(val % 10);
                c = val / 10;
                l1 = l1->next;
            }
            else {
                int val = l2->val + c;
                sum->next = new ListNode(val % 10);
                c = val / 10;
                l2 = l2->next;
            }
            sum = sum->next;
        }
        if(c){
            sum->next = new ListNode(c);
        }
        return sumHead->next;
    }
};