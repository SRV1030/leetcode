class Solution {
public:
    int r, c;
    int dp[71][71][71];
    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {
        if (i >= r || min(j1, j2) < 0 || max(j1, j2) >= c)
            return INT_MIN;

        int& ans = dp[i][j1][j2];
        if (ans != -1)
            return ans;

        int value = j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        ans = value;
        if (i == r - 1)
            return ans;

        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                int nextVal = solve(i + 1, j1 + x, j2 + y, grid);
                if (nextVal != INT_MIN) {
                    ans = max(ans, nextVal + value);
                }
            }
        }
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, c - 1, grid);
    }
};