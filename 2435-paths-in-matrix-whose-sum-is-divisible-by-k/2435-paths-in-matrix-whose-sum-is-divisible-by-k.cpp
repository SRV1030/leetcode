class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memo;
    int rows, cols;
public:
    int validPaths(vector<vector<int>>& grid, int k, int row, int col, int sum){
        if(min(row, col) < 0 || row >= rows || col >= cols)
            return 0;
        if(row == rows - 1 && col == cols - 1){
            return (sum + grid[row][col]) % k == 0;
        }
        int &paths = memo[row][col][sum];
        if(paths == -1){
            paths = (validPaths(grid, k, row + 1, col, (sum + grid[row][col]) % k) % MOD
                    + validPaths(grid, k, row, col + 1, (sum + grid[row][col]) % k) % MOD) % MOD;
        }
        return paths;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        memo = vector<vector<vector<int>>> (rows, vector<vector<int>>(cols, vector<int>(k, -1)));
        return validPaths(grid, k, 0, 0, 0);
    }
};