class Solution {
public:
    vector<vector<int>>dp;
    int subsetSum(int target,int q,int i, vector<vector<int>>& qr){
        if(!target) return q;
        if(q>=qr.size() || target<0) return qr.size()+1;
        int &ans=dp[q][target];
        if(ans!=-1) return ans;
        ans = subsetSum(target,q+1,i,qr);
        if(qr[q][0]<=i && i<=qr[q][1])ans=min(ans,subsetSum(target-qr[q][2],q+1,i,qr));
        return ans;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            dp=vector<vector<int>>(queries.size()+1,vector<int>(nums[i]+1,-1));
            ans=max(ans,subsetSum(nums[i],0,i,queries));
        }
        return ans>queries.size()?-1:ans;
    }
};