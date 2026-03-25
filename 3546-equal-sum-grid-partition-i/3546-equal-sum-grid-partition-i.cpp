class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<long long> rowSum(rows, 0), colSum(cols, 0);

        // Step 1: Compute row and column sums
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                rowSum[row] += grid[row][col];
                colSum[col] += grid[row][col];
            }
        }

        // Step 2: Compute total sums
        long long rsum = 0, csum = 0;
        for(int x : rowSum) rsum += x;
        for(int x : colSum) csum += x;

        // Step 3: Try partitioning rows
        long long rsum2 = 0;
        for(int row = 0; row < rows; ++row){
            rsum -= rowSum[row];
            rsum2 += rowSum[row];
            if(rsum == rsum2)
                return true;
        }

        // Step 4: Try partitioning columns
        long long csum2 = 0;
        for(int col = 0; col < cols; ++col){
            csum -= colSum[col];
            csum2 += colSum[col];
            if(csum == csum2)
                return true;
        }

        return false;
    }
};