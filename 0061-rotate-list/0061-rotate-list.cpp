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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n=1;
        ListNode *nh=head,*tail=head;
        while(tail->next && n++)tail=tail->next;
        tail->next=head;
        k%=n;
        if(k){
            k=n-k;
            while(k--)tail=tail->next;
        }
        nh=tail->next;
        tail->next=NULL;
        return nh;
    }
};