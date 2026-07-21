class Solution {
    queue<pair<int, pair<int,int>>> minHeap;
    vector<vector<int>> visited;
    int rows, cols;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    bool isOutOfBound(int row, int col){
        return min(row, col) < 0 || row >= rows || col >= cols || visited[row][col];
    }
    void dfs(vector<vector<int>>& grid, int row, int col){
        if(isOutOfBound(row, col) || !grid[row][col])
            return;
        visited[row][col] = 1;
        minHeap.push({0, {row, col}});
        for(auto& dir : directions)
            dfs(grid, row + dir[0], col + dir[1]);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited = vector<vector<int>>(rows, vector<int>(cols));
        bool found = false;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col]){
                    dfs(grid, row, col);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        while(!minHeap.empty()){
            auto [dist, position] = minHeap.front();
            minHeap.pop();
            for(auto& direction : directions){
                int row = position.first + direction[0], col = position.second + direction[1];
                if(isOutOfBound(row, col))
                    continue;
                if(grid[row][col] == 1)
                    return dist;
                visited[row][col] = 1;
                minHeap.push({dist + 1, {row, col}});
            }
        }
        return 0;
    }
};