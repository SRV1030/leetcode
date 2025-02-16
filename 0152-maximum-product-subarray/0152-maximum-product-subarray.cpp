class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=1,mn=1,ans=nums[0];
        for(auto&i:nums){
            int t = i*mx;
            mx = max({t,i*mn,i});
            mn = min({t,i*mn,i});
            ans=max(ans,mx);
        }
        return ans;
    }
};