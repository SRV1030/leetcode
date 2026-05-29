class Solution {
    int rows, cols;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int  row, int col, vector<vector<int>>& heights, vector<vector<int>>& ocean){
        ocean[row][col] = 1;
        for(auto& dir : directions){
            int x = dir[0] + row, y = dir[1] + col;
            if(min(x, y) < 0 || x >= rows || y >= cols || ocean[x][y] || heights[x][y] < heights[row][col])
                continue;
            dfs(x, y, heights, ocean);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<int>> pacific(rows, vector<int> (cols));
        vector<vector<int>> atlantic = pacific;
        vector<vector<int>> res;
        for(int row = 0; row < rows; ++row){
            dfs(row, 0, heights, pacific);
            dfs(row, cols - 1, heights, atlantic);
        }

        for(int col = 0; col < cols; ++col){
            dfs(0, col, heights, pacific);
            dfs(rows - 1, col, heights, atlantic);
        }

        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(pacific[row][col] && atlantic[row][col])
                    res.push_back({row, col});
            }
        }

        return res;
        
    }
};