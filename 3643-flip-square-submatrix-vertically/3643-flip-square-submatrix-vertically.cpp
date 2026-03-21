class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int row1 = x, row2 = x + k - 1; row1 < row2; ++row1, --row2){
            for(int col = y; col < y + k; ++col){
                swap(grid[row1][col], grid[row2][col]);
            }
        }
        return grid;
    }
};