class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0,csm=0;
        int l=0,r=0;
        set<int>st;
        while(r<size(nums)){
            if(st.count(nums[r])){
                while(!st.empty() && st.count(nums[r])){
                    st.erase(nums[l]);
                    csm-=nums[l++];
                }
            }
            else{
                csm+=nums[r];
                st.insert(nums[r++]);
            }
            if(st.size()==k){
                ans=max(ans,csm);
                st.erase(nums[l]);
                csm-=nums[l++];
            }
        }
        return ans;
    }
};