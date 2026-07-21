class Solution {
    int rows, cols;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int solve(vector<vector<int>>& grid, int row, int col){
        if(min(row, col) < 0 || row >= rows || col >= cols || grid[row][col] == 0)
            return 0;
        int coin = grid[row][col];
        int sum = coin;
        grid[row][col] = 0;
        for(auto& dir : directions){
            sum = max(sum , coin + solve(grid, row + dir[0], col + dir[1]));
        }
        grid[row][col] = coin;
        return sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int gold = 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col]){
                    gold = max(gold, solve(grid, row, col));
                }
            }
        }
        return gold;
    }
};