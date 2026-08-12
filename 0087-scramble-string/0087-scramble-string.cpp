class Solution {
    int dp[31][31][31];

    bool solve(string& s1, string& s2, int i, int j, int len) {
        if (dp[i][j][len] != -1)
            return dp[i][j][len];

        // Same substring
        bool same = true;

        for (int k = 0; k < len; ++k) {
            if (s1[i + k] != s2[j + k]) {
                same = false;
                break;
            }
        }

        if (same)
            return dp[i][j][len] = true;

        // Try every possible split
        for (int cut = 1; cut < len; ++cut) {

            // No swap
            if (solve(s1, s2, i, j, cut) &&
                solve(s1, s2, i + cut, j + cut, len - cut)) {

                return dp[i][j][len] = true;
            }

            // Swap
            if (solve(s1, s2, i, j + len - cut, cut) &&
                solve(s1, s2, i + cut, j, len - cut)) {

                return dp[i][j][len] = true;
            }
        }

        return dp[i][j][len] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0, s1.size());
    }
};