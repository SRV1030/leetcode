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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode *dum=new ListNode(0,head),*s=dum, *f=dum;
        ++n;
        while(n--)f=f->next;
        while(f){
            s=s->next;
            f=f->next;
        }
        s->next=s->next->next?s->next->next:NULL;
        return dum->next;
    }
};