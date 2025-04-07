class Solution {
public:
    vector<vector<int>>dp; 
    bool subsetSum(vector<int>& nums,int i,int sum){
        if(i>=nums.size()) return false;
        if(sum==0) return true;
        if(dp[i][sum]!=-1) return dp[i][sum] == 1;
        bool ans = false;
        ans|= subsetSum(nums,i+1,sum);
        if(nums[i]<=sum) ans|= subsetSum(nums,i+1,sum-nums[i]);
        dp[i][sum] = ans?1:2;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto&i:nums)sum+=i;
        if(sum%2) return false;
        sum/=2;
        dp.resize(nums.size()+1,vector<int>(sum+1,-1));
        return subsetSum(nums,0,sum);
    }
};