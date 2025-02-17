class Solution {
public:
    int dp[10001][2][101];
    int prof(int i, int buy, vector<int>& prices, int k) {
        if (i == prices.size() || k == 0)
            return 0;
        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];
        int profit = 0;
        if (buy) {
            int pick = -prices[i] + prof(i + 1, 0, prices, k);
            int not_pick = prof(i + 1, 1, prices, k);
            profit = max(pick, not_pick);
        } else {
            int pick = prices[i] + prof(i + 1, 1, prices, k-1);
            int not_pick = prof(i + 1, 0, prices, k);
            profit = max(pick, not_pick);
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return prof(0, 1, prices, k);
    }
};