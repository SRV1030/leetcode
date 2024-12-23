/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode *f=head,*s=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                ListNode *cur = head;
                while(cur!=s){
                    cur=cur->next;
                    s=s->next;
                }
                return cur;
            }
        }
        return NULL;
    }
};