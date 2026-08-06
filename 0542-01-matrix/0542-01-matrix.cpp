class Solution {
    int rowSize, colSize;
public:
    bool isOutOfBound(int row, int col){
        return min(row, col) < 0 || row >= rowSize || col >= colSize;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> bfsQueue;
        rowSize = mat.size();
        colSize = mat[0].size();

        vector<vector<int>> distanceMatrix(rowSize, vector<int>(colSize, INT_MAX));

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int row = 0; row < rowSize; row++)
            for(int col =0; col < colSize; col++){
                if(!mat[row][col]){
                    bfsQueue.push({row, col});
                }
            }
        int level = 0;
        while(!bfsQueue.empty()){
            int currentLevelSize = bfsQueue.size();
            while(currentLevelSize--){
                vector<int> node = bfsQueue.front();
                bfsQueue.pop();
                int row = node[0], col = node[1];
                if(distanceMatrix[row][col] > level){
                    distanceMatrix[row][col] = level;
                    for(auto& direction: directions){
                        int nextRow = row + direction[0], nextCol = col + direction[1];
                        if(!isOutOfBound(nextRow, nextCol))
                            bfsQueue.push({nextRow, nextCol});
                    }
                }
            }
            level++;
        }
        return distanceMatrix;
    }
};