class Solution {
    int n, l, r;
    const int MOD = 1e9 + 7;

    vector<vector<vector<long long>>> dp;

public:
    long long count(int ind, int prev, int isInc) {
        if (ind == 0)
            return 1;

        long long &res = dp[ind][isInc][prev];
        if (res != -1)
            return res;

        res = 0;

        int next = prev + (isInc ? 1 : -1);

        if (next >= l && next <= r) {
            res = (
                count(ind - 1, next, !isInc) +
                count(ind, next, isInc)
            ) % MOD;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        this->n = n;
        this->l = l;
        this->r = r;

        dp.assign(
            n + 1,
            vector<vector<long long>>(2,
                vector<long long>(r + 2, -1))
        );

        return (2LL * count(n, r + 1, 0)) % MOD;
    }
};