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
    // ListNode* rev(ListNode* h){
    //     if(!h) return;
    //     ListNode* cur=h,nxt=NULL,prev=NULL;
    //     while(cur){
    //         nxt=cur->next;
    //         cur->next=prev;
    //         prev=cur;
    //         cur=nxt;
    //     }
    //     return prev;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur=new ListNode(0), *ans=cur;
        int c=0;
        while(l1 && l2){
            int v=l1->val+l2->val+c;
            c=v/10;
            cur->next=new ListNode(v%10);
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int v=l1->val+c;
            c=v/10;
            cur->next=new ListNode(v%10);
            cur=cur->next;
            l1=l1->next;
        }
        while(l2){
            int v=l2->val+c;
            c=v/10;
            cur->next=new ListNode(v%10);
            cur=cur->next;
            l2=l2->next;
        }
        if(c)cur->next=new ListNode(c);
        return ans->next;
    }
};