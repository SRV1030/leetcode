class Solution {
public:
    long long dp[100001];
    long long solve(int i, vector<vector<int>>& qs) {
        if (i >= qs.size())
            return 0;
        long long& ans = dp[i];
        if (ans != -1)
            return ans;
        long long pick = qs[i][0] + solve(i + qs[i][1] + 1, qs);
        long long not_pick = solve(i + 1, qs);
        return ans = max(pick, not_pick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        return solve(0, questions);
    }
};