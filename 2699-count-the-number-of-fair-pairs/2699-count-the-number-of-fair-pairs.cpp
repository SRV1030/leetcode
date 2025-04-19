class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i = 0; i<nums.size();i++){
            auto mn = lower_bound(nums.begin()+i+1,nums.end(),lower - nums[i]);
            auto mx = upper_bound(nums.begin()+i+1,nums.end(),upper - nums[i]);
            ans+=(mx-mn);
        }
        return ans;
    }
};