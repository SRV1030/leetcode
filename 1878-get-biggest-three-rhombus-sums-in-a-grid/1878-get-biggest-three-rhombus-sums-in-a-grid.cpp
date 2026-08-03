class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // ↘ diagonal prefix
        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));

        // ↙ diagonal prefix
        vector<vector<int>> diag2(m + 1, vector<int>(n + 2, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];

        for (int i = 0; i < m; i++)
            for (int j = n - 1; j >= 0; j--)
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];

        set<int, greater<int>> ans;

        // radius = 0
        for (auto &row : grid)
            for (int x : row)
                ans.insert(x);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                for (int k = 1;
                     r + 2 * k < m &&
                     c - k >= 0 &&
                     c + k < n;
                     k++) {

                    // Four edges (corners included)
                    int e1 = diag1[r + k + 1][c + k + 1] - diag1[r][c];
                    int e2 = diag2[r + 2 * k + 1][c] - diag2[r + k][c + k + 1];
                    int e3 = diag1[r + 2 * k + 1][c + 1] - diag1[r + k][c - k];
                    int e4 = diag2[r + k + 1][c - k] - diag2[r][c + 1];

                    int sum = e1 + e2 + e3 + e4;

                    // remove duplicated corners
                    sum -= grid[r][c];
                    sum -= grid[r + k][c + k];
                    sum -= grid[r + 2 * k][c];
                    sum -= grid[r + k][c - k];

                    ans.insert(sum);
                }
            }
        }

        vector<int> res;
        for (int x : ans) {
            res.push_back(x);
            if (res.size() == 3) break;
        }
        return res;
    }
};