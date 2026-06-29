class Solution {
    long long topSum, bottomSum;
    vector<long long> topFrequency, bottomFrequency;
    int rows, cols;
public:
    bool removeAndCheckTop(vector<vector<int>>& grid, long long diff, int height, int index){
        if(diff < 0 || diff > 1e5)
            return false;

        if(height > 1 && cols > 1) 
            return topFrequency[diff];

        if(height > 1 && cols == 1)
            return grid[0][0] == diff || grid[index][0] == diff;
        
        if(height == 1 && cols > 1)
            return grid[0][0] == diff || grid[0][cols - 1] == diff;

        return false;
    }

    bool removeAndCheckBottom(vector<vector<int>>& grid, long long diff, int height, int index){
        if(diff < 0 || diff > 1e5)
            return false;

        if(height > 1 && cols > 1) 
            return bottomFrequency[diff];

        if(height > 1 && cols == 1)
            return grid[rows - 1][0] == diff || grid[index + 1][0] == diff;
        
        if(height == 1 && cols > 1)
            return grid[rows - 1][0] == diff || grid[rows - 1][cols - 1] == diff;

        return false;
    }
    bool solve(vector<vector<int>>& grid){
        rows = grid.size();
        cols = grid[0].size();
        topSum = bottomSum = 0ll;
        topFrequency.assign(100001, 0);
        bottomFrequency = topFrequency;

        for(int row = 0; row < rows; ++row)
            for(int col = 0; col < cols; ++col){
                bottomSum += grid[row][col];
                bottomFrequency[grid[row][col]]++;
            }
        
        for(int row = 0; row < rows - 1; ++row){
            for(int col = 0; col < cols; ++col){
                topSum += grid[row][col];
                topFrequency[grid[row][col]]++;
                bottomSum -= grid[row][col];
                bottomFrequency[grid[row][col]]--;
            }
            if(topSum == bottomSum)
                return true;
            else if(topSum > bottomSum){
                if(removeAndCheckTop(grid, topSum - bottomSum, row + 1, row))
                    return true;
            }
            else{
                if(removeAndCheckBottom(grid, bottomSum - topSum, rows - row - 1, row))
                    return true;
            }
        }

        return false;
    }
    vector<vector<int>> transpose(vector<vector<int>>& grid){
        vector<vector<int>> mat(grid[0].size(), vector<int>(grid.size()));
        for(int row = 0; row < grid.size(); ++row){
            for(int col = 0; col < grid[0].size(); ++col){
                mat[col][row] = grid[row][col];
            }
        }
        return mat;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(solve(grid))
            return true;
        grid = transpose(grid);
        return solve(grid);
    }
};