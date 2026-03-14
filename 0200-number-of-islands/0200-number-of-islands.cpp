class Solution {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int rows, cols;
public:
    void dfs(int row, int col, vector<vector<char>>&  grid){
        if(min(row, col) < 0 || row >= rows || col >= cols || grid[row][col] != '1')
            return;
        grid[row][col] = '0';
        for(auto& dir : directions)
            dfs(row + dir[0], col + dir[1], grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col] == '1'){
                    ++count;
                    dfs(row, col, grid);
                }
            }
        }
        return count;
    }
};