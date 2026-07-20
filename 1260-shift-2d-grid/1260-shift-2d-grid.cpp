class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size(), total = rows * cols;
        k = k % total;
        if(!k)
            return grid;
        vector<vector<int>> ans(rows, vector<int>(cols));
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                int index = (row * cols) + col;
                index = (index + k) % total;
                ans[index / cols][index % cols] = grid[row][col];
            }
        }
        return ans;
    }
};