class Solution {
    int memo[301][5001];
    const int LOCAL_MAX = 1e9 + 7;
public:
    int solve(int amount, int index, vector<int>& coins){
        if(amount == 0)
            return 1;
        if(index == coins.size()){
            return 0; 
        }
        int& ways = memo[index][amount];
        if(ways == -1){
            ways = solve(amount, index + 1, coins);
            if(amount >= coins[index]){
                ways += solve(amount - coins[index], index, coins);
            }
        }
        return ways;
    }
    int change(int amount, vector<int>& coins) {
        memset(memo, -1, sizeof(memo));
        int val = solve(amount, 0, coins);
        return val;
    }
};  