class Solution {
public:
    vector<long long>prefixNums,prefixCosts;
    int size;
    long long dp[1001];
    long long getCostSum(int i,int j){
        return prefixCosts[j]-(((i-1)>=0)?prefixCosts[i-1]:0);
    }

    long long getSubArraySum(int i,int j,int k){
        return prefixNums[j]*getCostSum(i,j)+k*getCostSum(i,size-1);
    }

    long long minSubArrayCost(int i,int k){
        if(i>=size) return 0;
        long long &mnCost = dp[i];
        if(mnCost!=-1) return mnCost;
        mnCost = LONG_MAX;
        for(int j=i;j<size;j++){
            long long subArrayCost = minSubArrayCost(j+1,k);
            mnCost=min(mnCost,subArrayCost+getSubArraySum(i,j,k));
        }
        return mnCost;
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        size = nums.size();
        memset(dp,-1,sizeof(dp));
        prefixNums.push_back(nums[0]);
        prefixCosts.push_back(cost[0]);
        for(int i=1;i<size;i++){
            prefixNums.push_back(prefixNums[i-1]+nums[i]);
            prefixCosts.push_back(prefixCosts[i-1]+cost[i]);
        }
        return minSubArrayCost(0,k);
    }
};