class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> prefixSum(rows, vector<vector<int>>(cols, vector<int>(2)));
        int count = 0;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col] != '.'){
                    int ind = grid[row][col] == 'X';
                    prefixSum[row][col][ind]++;
                }
                if(row){
                    prefixSum[row][col][0] += prefixSum[row - 1][col][0];
                    prefixSum[row][col][1] += prefixSum[row - 1][col][1];
                }
                if(col){
                    prefixSum[row][col][0] += prefixSum[row][col - 1][0];
                    prefixSum[row][col][1] += prefixSum[row][col - 1][1];
                }
                if(row && col){
                    prefixSum[row][col][0] -= prefixSum[row - 1][col - 1][0];
                    prefixSum[row][col][1] -= prefixSum[row - 1][col - 1][1];
                }
                if(prefixSum[row][col][0] == prefixSum[row][col][1] && prefixSum[row][col][0] > 0) {
                        count++;
                }
            }
        }
        return count;
    }
};