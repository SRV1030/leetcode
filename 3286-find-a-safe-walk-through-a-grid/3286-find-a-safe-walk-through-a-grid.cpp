class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> best(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0)
            return false;

        best[0][0] = startHealth;
        q.push({0, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == rows - 1 && c == cols - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                int newHealth = best[r][c] - grid[nr][nc];

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[nr][nc]) {
                    best[nr][nc] = newHealth;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};