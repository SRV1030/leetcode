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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int first = -1;
        int last = -1;
        int minDis = INT_MAX;

        int index = 1;

        while(next) {
            if((curr->val > prev->val && curr->val > next->val) ||
               (curr->val < prev->val && curr->val < next->val)) {

                if(first == -1) {
                    first = index;
                }
                else {
                    minDis = min(minDis, index - last);
                }
                last = index;
            }

            prev = curr;
            curr = next;
            next = next->next;
            ++index;
        }

        // Fewer than 2 critical points
        if(first == -1 || first == last)
            return {-1, -1};

        int maxDis = last - first;

        return {minDis, maxDis};
    }
};