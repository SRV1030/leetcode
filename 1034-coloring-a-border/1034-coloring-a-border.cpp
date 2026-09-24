class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> impactedBorders;

        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({row, col});

        int rows = grid.size();
        int cols = grid[0].size();

        int originalColor = grid[row][col];

        vector<vector<int>> visited(rows, vector<int>(cols));

        vector<vector<int>> directions = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        visited[row][col] = 1;

        while (!bfsQueue.empty()) {
            auto [x, y] = bfsQueue.front();
            bfsQueue.pop();

            bool isBorder = false;

            for (auto& dir : directions) {
                int a = x + dir[0];
                int b = y + dir[1];

                // Outside grid -> current cell is a border
                if (a < 0 || b < 0 || a >= rows || b >= cols) {
                    isBorder = true;
                    continue;
                }

                // Different color -> current cell is a border
                if (grid[a][b] != originalColor) {
                    isBorder = true;
                    continue;
                }

                // Same component -> BFS
                if (!visited[a][b]) {
                    visited[a][b] = 1;
                    bfsQueue.push({a, b});
                }
            }

            if (isBorder)
                impactedBorders.push_back({x, y});
        }

        for (auto& border : impactedBorders)
            grid[border[0]][border[1]] = color;

        return grid;
    }
};