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
    ListNode* merge(ListNode* node1, ListNode* node2) {
        if(!node1)
            return node2;
        if(!node2)
            return node1;
        if(node1 == node2)
            return node1;
        ListNode *head = new ListNode(), *current = head;
        while (node1 && node2) {
            if (node1->val <= node2->val) {
                current->next = new ListNode(node1->val);
                node1 = node1->next;
            } else {
                current->next = new ListNode(node2->val);
                node2 = node2->next;
            }
            current = current->next;
        }
        while (node1) {
            current->next = new ListNode(node1->val);
            node1 = node1->next;
            current = current->next;
        }
        while (node2) {
            current->next = new ListNode(node2->val);
            node2 = node2->next;
            current = current->next;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sizeOfList = lists.size();
        if (sizeOfList == 0)
            return NULL;
        if (sizeOfList == 1)
            return lists[0];
        vector<ListNode*> nextList;
        for (int leftIndex = 0, rightIndex = sizeOfList -1; leftIndex <= rightIndex; leftIndex++, rightIndex--)
            nextList.push_back(merge(lists[leftIndex], lists[rightIndex]));
        return mergeKLists(nextList);
    }
};