class Solution {
public:
    int rowSize, colSize, checkBorder;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int row, int col) {
        bool crossesBorder =
            min(row, col) < 0 || row >= rowSize || col >= colSize;
        if (crossesBorder || grid[row][col] != 0) {
            if (crossesBorder)
                checkBorder = 1;
            return;
        }
        grid[row][col] = 2;
        for (auto& dir : directions)
            dfs(grid, row + dir[0], col + dir[1]);
    }
    int closedIsland(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        int countCLosedIsland = 0;
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                if (grid[row][col] == 0) {
                    checkBorder = 0;
                    dfs(grid, row, col);
                    if (!checkBorder)
                        ++countCLosedIsland;
                }
            }
        }
        return countCLosedIsland;
    }
};