class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>& cs, int at,int i){
        if(at==0) return 0;
        if(i==cs.size() || at<0) return INT_MAX;
        if(dp[i][at]!=-1) return dp[i][at];
        int take = INT_MAX;
        if(cs[i]>0){
            take=solve(cs,at-cs[i],i);
            if(take!=INT_MAX)take++;
        }
        int notTake = solve(cs,at,i+1);
        return dp[i][at]=min(take,notTake); 
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,amount,0);
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};