class Solution {
public:
    bool isOutOfBound(int row, int col, int numberOfRows, int numberOfCols){
        return min(row, col) < 0 || row >= numberOfRows || col >= numberOfCols;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int numberOfRows = heights.size(), numberOfCols = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> bfsMinHeap;
        bfsMinHeap.push({0,0,0});

        vector<vector<int>> maxDifferenceRowCol(numberOfRows, vector<int>(numberOfCols, INT_MAX));
        vector<vector<int>> directions = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        maxDifferenceRowCol[0][0] = 0;
        
        while(!bfsMinHeap.empty()){
            vector<int> nodeState = bfsMinHeap.top();
            bfsMinHeap.pop();
            int heightDifference = nodeState[0], row = nodeState[1], col = nodeState[2];
            if(row == numberOfRows - 1 && col == numberOfCols - 1)
                return heightDifference;
            for(auto& direction : directions){
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if(isOutOfBound(nextRow, nextCol, numberOfRows, numberOfCols))
                    continue;
                int absHeightDifference = abs(heights[nextRow][nextCol] - heights[row][col]);
                int maxHeightDifference = max(absHeightDifference, heightDifference);
                if(heightDifference < maxDifferenceRowCol[nextRow][nextCol]){
                    bfsMinHeap.push({maxHeightDifference, nextRow, nextCol});
                    maxDifferenceRowCol[nextRow][nextCol] = maxHeightDifference;
                }
            }
        }
        return -1;
    }
};