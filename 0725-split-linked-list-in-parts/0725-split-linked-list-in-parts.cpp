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
    int sizeList(ListNode* head){
        int l=0;
        while(head!=nullptr){
            ++l;
            head=head->next;
        }
        return l;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur=head;
        int lsz = sizeList(cur);
        int sz=lsz/k;
        int fsz=lsz%k;
        vector<ListNode*> ans;
        while(k--){
            int n = sz + (fsz!=0);
            if(fsz!=0)--fsz;
            ListNode x(0);
            ListNode* temp=&x;
            while(n--){
                temp->next = new ListNode(head->val);
                temp=temp->next;
                head=head->next;
            }
            ans.push_back(x.next);
        }
        return ans;
    }
};