class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int left = 0, top = 0, bottom = grid.size() - 1, right = grid[0].size() - 1;
        while(left < right && top < bottom){
            vector<int> layer;
            for(int ind = left; ind <= right; ++ind)
                layer.push_back(grid[top][ind]);
            for(int ind = top + 1; ind <= bottom; ++ind)
                layer.push_back(grid[ind][right]);
            for(int ind = right - 1; ind >= left; --ind)
                layer.push_back(grid[bottom][ind]);
            for(int ind = bottom - 1; ind > top; --ind)
                layer.push_back(grid[ind][left]);

            int idx = 0;
            int size = layer.size();

            for(int ind = left; ind <= right; ++ind, ++idx)
                grid[top][ind] = layer[(idx + k) % size];
            for(int ind = top + 1; ind <= bottom; ++ind, ++idx)
                grid[ind][right] = layer[(idx + k) % size];
            for(int ind = right - 1; ind >= left; --ind, ++idx)
                grid[bottom][ind] = layer[(idx + k) % size];
            for(int ind = bottom - 1; ind > top; --ind, ++idx)
                grid[ind][left] = layer[(idx + k) % size];
            
            ++left;
            ++top;
            --bottom;
            --right;
        }

        return grid;
    }
};