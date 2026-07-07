class Solution {
    long long memo[101][101][2];
    int size;
    vector<vector<long long>> prefixColSum;

public:
    void fillSum(vector<vector<int>>& grid) {
        prefixColSum.assign(size + 1, vector<long long>(size, 0));

        for (int col = 0; col < size; ++col) {
            for (int row = 0; row < size; ++row) {
                prefixColSum[row + 1][col] =
                    prefixColSum[row][col] + grid[row][col];
            }
        }
    }

    long long solve(int col, int prevHt, int flag) {
        if (col == size)
            return 0;

        long long &res = memo[col][prevHt][flag];
        if (res != -1)
            return res;

        res = 0;

        for (int ht = 0; ht <= size; ++ht) {
            long long gain;

            if (ht < prevHt) {
                // Decrease
                gain = prefixColSum[prevHt][col] -
                       prefixColSum[ht][col] +
                       solve(col + 1, ht, 1);
            }
            else if (ht > prevHt && !flag && col > 0) {
                // Increase
                gain = prefixColSum[ht][col - 1] -
                       prefixColSum[prevHt][col - 1] +
                       solve(col + 1, ht, 0);
            }
            else {
                // Equal height or blocked increase
                gain = solve(col + 1, ht, 0);
            }

            res = max(res, gain);
        }

        return res;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        size = grid.size();
        memset(memo, -1, sizeof(memo));

        fillSum(grid);

        return solve(0, 0, 1);
    }
};