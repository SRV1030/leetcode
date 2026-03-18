class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = 0;
        for(int row = 0; row < grid.size(); ++row){
            for(int col = 0; col < grid[0].size(); ++col){
                if(row != 0)
                    grid[row][col] += grid[row - 1][col];
                if(col != 0)
                    grid[row][col] += grid[row][col - 1];
                if(row && col)
                    grid[row][col] -= grid[row - 1][col - 1];
                if(grid[row][col] <= k)
                    ++count;
            }
        }
        return count;
    }
};