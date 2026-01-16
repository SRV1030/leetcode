class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size() + 1, INT_MAX);
        memo[0] = memo[1] = 0;
        for(int index = 2; index <= cost.size(); ++index){
            memo[index] = min(cost[index - 1] + memo[index - 1], cost[index - 2] + memo[index - 2]);
        }
        return memo[cost.size()];
    }
};