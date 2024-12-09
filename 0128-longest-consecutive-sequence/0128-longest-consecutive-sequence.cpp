class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(begin(nums),end(nums));
        int mx=0;
        for(auto&i:nums){
            int cur=i,cmx=1;
            if(!st.count(cur-1)){
                while(st.count(cur+1)){
                    cmx++;
                    cur++;
                }
                mx=max(mx,cmx);
            }
        }
        return mx;
    }
};