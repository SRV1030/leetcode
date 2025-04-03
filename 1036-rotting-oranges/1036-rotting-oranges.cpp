class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> rottenQueue;
        int timeLapsed = -1;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int row = 0; row < grid.size(); row++)
            for (int column = 0; column < grid[0].size(); column++)
                if (grid[row][column] == 2)
                    rottenQueue.push({row, column});
        while (!rottenQueue.empty()) {
            int rottenQueueSize = rottenQueue.size();
            while (rottenQueueSize--) {
                vector<int> rottenOrange = rottenQueue.front();
                rottenQueue.pop();
                for (auto& direction : directions) {
                    int newRow = rottenOrange[0] + direction[0],
                        newColumn = rottenOrange[1] + direction[1];
                    if (min(newRow, newColumn) < 0 || newRow >= grid.size() ||
                        newColumn >= grid[0].size() ||
                        grid[newRow][newColumn] != 1)
                        continue;
                    grid[newRow][newColumn] = 2;
                    rottenQueue.push({newRow, newColumn});
                }
            }
            timeLapsed++;
        }
        for (int row = 0; row < grid.size(); row++)
            for (int column = 0; column < grid[0].size(); column++)
                if (grid[row][column] == 1)
                    return -1;
        return max(0,timeLapsed);
    }
};