class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dist(
            rows, vector<int>(cols, INT_MAX)
        );

        deque<pair<int,int>> dq;

        // right, left, down, up
        vector<vector<int>> dir = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        dq.push_front({0,0});
        dist[0][0] = 0;

        while(!dq.empty()) {

            auto [r,c] = dq.front();
            dq.pop_front();

            for(int d=0; d<4; d++) {

                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr<0 || nc<0 || nr>=rows || nc>=cols)
                    continue;

                // 0 if current cell already points there
                // otherwise modify sign once (cost=1)
                int wt = (grid[r][c] == d+1) ? 0 : 1;

                if(dist[nr][nc] > dist[r][c] + wt){

                    dist[nr][nc] = dist[r][c] + wt;

                    if(wt==0)
                        dq.push_front({nr,nc});
                    else
                        dq.push_back({nr,nc});
                }
            }
        }

        return dist[rows-1][cols-1];
    }
};