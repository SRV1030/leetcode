class Solution {
    const int LOCAL_MAX = 1e9 + 7;
    int memory[501][501];
public:
    int getCost(vector<int>& costs, vector<int>& time, int index, int walls){
        if(walls <= 0)
            return 0;
        if(index >= costs.size())
            return LOCAL_MAX;
        int& cost = memory[index][walls];
        if(cost == -1){
            cost = min(getCost(costs, time, index + 1, walls),
                        costs[index] + getCost(costs, time, index + 1, walls - time[index] - 1));
        }
        return cost;
    }
    int paintWalls(vector<int>& costs, vector<int>& time) {
        memset(memory, -1, sizeof(memory));
        return getCost(costs, time, 0, costs.size());
    }
};