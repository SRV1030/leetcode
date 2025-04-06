class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size(),dp[size],mx=1,prev=-1;
        dp[0]=1;
        for(int i=1;i<size;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j])
                    dp[i]=1+dp[j];
            }
            mx=max(mx,dp[i]);
        } 
        vector<int> ans;
        for(int j=size-1;j>=0;j--){
            if(dp[j]==mx && (prev==-1 || prev%nums[j]==0)){
                ans.push_back(nums[j]);
                prev=nums[j];
                --mx;
            }
        } 
        return ans;
    }
};