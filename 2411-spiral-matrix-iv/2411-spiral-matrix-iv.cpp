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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i=0,j=0;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        while(i<m &&j<n){
            for(int k=j;k<n;++k){
                if(!head) return ans;
                ans[i][k]=head->val;
                head=head->next;
            }
            ++i;
            for(int k=i;k<m;++k){
                if(!head) return ans;
                ans[k][n-1]=head->val;
                head=head->next;
            }
            --n;
            if(j<n){
                for(int k=n-1;k>=j;--k){
                    if(!head) return ans;
                    ans[m-1][k]=head->val;
                    head=head->next;
                }
                --m;
            }
            if(i<m){
                for(int k=m-1;k>=i;--k){
                    if(!head) return ans;
                    ans[k][j]=head->val;
                    head=head->next;
                }
                ++j;
            }
        }
        return ans;
    }
};