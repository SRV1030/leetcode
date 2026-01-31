class Solution {
    static const int MOD = 1e9 + 7;
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<int> prev(n), next(n);
        vector<int> last(4, -1);

        // prev occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            prev[i] = last[c];
            last[c] = i;
        }

        fill(last.begin(), last.end(), -1);

        // next occurrence
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            next[i] = last[c];
            last[c] = i;
        }

        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                long long mid = (l + 1 <= r - 1) ? dp[l+1][r-1] : 0;

                if (s[l] != s[r]) {
                    dp[l][r] = dp[l+1][r] + dp[l][r-1] - mid;
                } else {
                    int low = next[l];
                    int high = prev[r];

                    if (low == -1 || low >= r) {
                        dp[l][r] = 2 * mid + 2;
                    }
                    else if (low == high) {
                        dp[l][r] = 2 * mid + 1;
                    }
                    else {
                        dp[l][r] = 2 * mid - dp[low+1][high-1];
                    }
                }

                dp[l][r] %= MOD;
                if (dp[l][r] < 0) dp[l][r] += MOD;
            }
        }

        return dp[0][n-1];
    }
};
