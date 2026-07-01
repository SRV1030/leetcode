class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if(grid[0][0] || grid[rows - 1][cols - 1])
            return 0;
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> bfsQ;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col]){
                    bfsQ.push({row, col});
                    distance[row][col] = 0;
                }
            }
        }

        while(!bfsQ.empty()){
            auto [row, col] = bfsQ.front();
            bfsQ.pop();
            for(auto& dir : directions){
                int nr = dir[0] + row, nc = dir[1] + col;
                if(min(nr, nc) < 0 || nr >= rows || nc >= cols)
                    continue;
                if(distance[nr][nc] > distance[row][col] + 1){
                    distance[nr][nc] = distance[row][col] + 1;
                    bfsQ.push({nr, nc});
                }
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        vector<vector<int>> best(rows, vector<int>(cols, -1));

        best[0][0] = distance[0][0];
        pq.push({distance[0][0], 0, 0});

        while (!pq.empty()) {
            auto [safe, r, c] = pq.top();
            pq.pop();

            if (r == rows - 1 && c == cols - 1)
                return safe;

            if (safe < best[r][c])
                continue;

            for (auto dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                int newSafe = min(safe, distance[nr][nc]);

                if (newSafe > best[nr][nc]) {
                    best[nr][nc] = newSafe;
                    pq.push({newSafe, nr, nc});
                }
            }
        }
        return 0;
    }
};