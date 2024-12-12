/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *cur=head,*cpy=NULL,*ans;
        while(cur){
            cpy = new Node(cur->val);
            cpy->next=cur->next;
            cur->next=cpy;
            cur=cur->next->next;
        }
        cur=head;
        while(cur){
            if(cur->random)cur->next->random=cur->random->next;
            cur=cur->next->next;
        }
        cur=head;
        ans=cur->next;
        cpy=ans;
        while(cur){
            cur->next=cur->next->next;
            cpy->next=cpy->next?cpy->next->next:NULL;
            cur=cur->next;
            cpy=cpy->next;
        }
        return ans;
    }
};