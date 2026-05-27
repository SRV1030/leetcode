class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> heap;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        heap.push({0, 0, 0});
        distance[0][0] = 0;
        while(!heap.empty()){
            vector<int> state = heap.top();
            heap.pop();
            int cost = state[0], row = state[1], col = state[2];
            for(int dir = 0; dir < 4; ++dir){
                int x = row + directions[dir][0], y = col + directions[dir][1];
                if(min(x, y) < 0 || x >= rows || y >= cols)
                    continue;
                int wt = grid[row][col] == (dir + 1) ? 0 : 1;
                if(distance[x][y] > wt + cost){
                    distance[x][y] = wt + cost;
                    heap.push({distance[x][y], x, y});
                }
            }
        }
        return distance[rows - 1][cols - 1];
    }
};