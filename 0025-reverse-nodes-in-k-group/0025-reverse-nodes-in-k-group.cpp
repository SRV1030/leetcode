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
    int count(ListNode* head){
        ListNode *p=head;
        int c=0;
        while(p){
            p=p->next;
            ++c;
        }
        return c;
    }
    ListNode* reverse(ListNode* head,int k,int rem){
        if(!head || rem<k) return head;
        ListNode *cur=head,*prev=NULL,*nxt=NULL;
        int c=0;
        while(cur && c<k){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            ++c;
        }
        if(nxt) head->next=reverse(nxt,k,rem-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k,count(head));
    }
};