class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1);
        dp[0]=1;
        int md=1e9+7,ans=0;
        for(int i=1;i<=high;i++){
            if(i>=zero)dp[i]+=dp[i-zero];
            if(i>=one)dp[i]+=dp[i-one];
            dp[i]%=md;
            if(i>=low) ans=(ans%md+dp[i]%md)%md;
        }
        return ans;
    }
};