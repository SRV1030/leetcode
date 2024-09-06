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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode t(0,head);
        unordered_set<int> st(begin(nums), end(nums));
        for(auto *p=&t;p->next;){
            if(st.count(p->next->val)){
                p->next=p->next->next;
            }
            else p=p->next;
        }
        return t.next;
    }
};