class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<unsigned long long>> dp(size + 1, vector<unsigned long long>(amount + 1));

        for(int ind = 0; ind <= size; ++ind)
            dp[ind][0] = 1;

        for(int index = size - 1; index >= 0; --index){
            for(int am = 1; am <= amount; ++am){
                dp[index][am] = dp[index + 1][am];
                if(am >= coins[index])
                    dp[index][am] += dp[index][am - coins[index]];
            }
        }
        return dp[0][amount];
    }
};  