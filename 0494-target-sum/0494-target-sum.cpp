class Solution {
public:
    int dp[21][30005];
    int solve(vector<int>& nums,int sm,int i){
        if(i==nums.size()){
            if(sm==0) return 1;
            return 0; 
        }
        if(dp[i][sm+1000]!=-1) return dp[i][sm+1000];
        return dp[i][sm+1000] = solve(nums,sm,i+1) + solve(nums,sm-nums[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=accumulate(nums.begin(),nums.end(),0);
        s=s-target;
        if(s<0 || s%2) return 0;
        s/=2;
        memset(dp,-1,sizeof(dp));
        return solve(nums,s,0);
    }
};