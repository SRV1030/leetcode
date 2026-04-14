#define ll long long
class Solution {
    ll memo[101][101][101];
    const ll MAX_VAL = 1e18;
public:
    ll solve(int rI, int fI, int count, vector<int>& robot, vector<vector<int>>& factory){
        if(rI >= robot.size())
            return 0;
        if(fI >= factory.size())
            return MAX_VAL;
        ll &res = memo[rI][fI][count];

        if(res == -1){
            ll skip = solve(rI, fI + 1, 0, robot, factory);
            ll take = MAX_VAL;
            if(count < factory[fI][1])
                take = abs(robot[rI] - factory[fI][0]) + solve(rI + 1, fI, count + 1, robot, factory);
            res = min(skip, take);
        }
        return res;
    }
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, robot, factory);
    }
};