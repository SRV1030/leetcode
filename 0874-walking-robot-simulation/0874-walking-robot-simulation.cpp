class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> obs(obstacles.begin(), obstacles.end());
        int res = 0, x = 0, y = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        for(auto& command : commands){
            if(command == -1){
                dir = (dir + 1) % 4;
                continue;
            }
            if(command == -2){
                dir = (dir + 3) % 4;
                continue;
            }
            for(int step = 0; step < command; ++step){
                if(obs.count({x + directions[dir][0], y + directions[dir][1]}))
                    break;
                x += directions[dir][0];
                y += directions[dir][1];
            }
            res = max(res, x * x + y * y);
        }
        return res;
    }
};