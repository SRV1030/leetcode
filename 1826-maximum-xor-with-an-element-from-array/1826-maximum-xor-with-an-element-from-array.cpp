class Solution {
public:
    class Node{
    public:
        int val;
        Node* child[2];
        Node(){
            val=-1;
            for(int i=0;i<2;i++)child[i]=nullptr;
        }
    };
    class Trie{
    public:
        Node *root;
        Trie(){
            root=new Node();
        }
        void insert(int x){
            Node *t=root;
            for(int i=31;i>=0;i--){
                int b = ((x>>i)&1);
                if(!t->child[b])t->child[b]=new Node();
                t=t->child[b];
            }
            t->val=x;
        }
        int findMax(int x){
            Node *t=root;
            for(int i=31;i>=0;i--){
                int b = ((x>>i)&1),inv=!b;
                if(!t->child[inv]) t=t->child[b];
                else t=t->child[inv];
            }
            return t->val;
        }
    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int nq=queries.size(),n=nums.size();
        vector<int> ans(nq);
        sort(nums.begin(),nums.end());
        vector<vector<int>>buildQ;
        for(int i=0;i<nq;i++) buildQ.push_back({queries[i][1],queries[i][0],i});
        sort(buildQ.begin(),buildQ.end());
        int j=0;
        Trie tr;
        for(auto&q:buildQ){
            int ind=q[2],m=q[0],xr=q[1];
            while(j<n && nums[j]<=m){
                tr.insert(nums[j]);
                ++j;
            }
            ans[ind]=j==0?-1:tr.findMax(xr)^xr;
        }
        return ans;
    }
};