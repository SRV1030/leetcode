class Solution {
    int rowSize, colSize;
    bool isOutofBound(int row, int col){
        return min(row, col) < 0 || row >= rowSize || col >= colSize;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        vector<vector<int>> visited(rowSize, vector<int>(colSize));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        int maxElevation = -1;
        while(!minHeap.empty()){
            auto [elevation, row, col] = minHeap.top();
            minHeap.pop();
            maxElevation = max(maxElevation, elevation);
            if(row == rowSize - 1 && col == colSize - 1)
                return maxElevation;
            for(auto& direction: directions){
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if(isOutofBound(nextRow, nextCol) || visited[nextRow][nextCol])
                    continue;
                visited[nextRow][nextCol] = 1;
                minHeap.push({grid[nextRow][nextCol], nextRow, nextCol});
            }
        }
        return -1;
    }
};