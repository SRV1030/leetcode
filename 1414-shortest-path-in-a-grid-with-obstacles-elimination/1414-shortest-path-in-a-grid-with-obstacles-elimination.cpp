class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> visited(rows, vector<int>(columns, -1));
        queue<vector<int>> simulationQueue;

        simulationQueue.push({0, 0, 0, k});

        while (!simulationQueue.empty()) {
            auto currentStats = simulationQueue.front();
            simulationQueue.pop();

            int x = currentStats[0], y = currentStats[1],
                distanceCovered = currentStats[2], kValue = currentStats[3];

            if (min(x, y) < 0 || x >= rows || y >= columns)
                continue;

            if (x == rows - 1 && y == columns - 1)
                return distanceCovered;

            if (grid[x][y]) {
                if (kValue>0)
                    kValue--;
                else
                    continue;
            }

            if (visited[x][y] != -1 && visited[x][y] >= kValue)
                continue;

            visited[x][y] = kValue;

            for (auto& direction : directions)
                simulationQueue.push({x + direction[0], y + direction[1],
                                      1 + distanceCovered, kValue});
        }
        return -1;
    }
};