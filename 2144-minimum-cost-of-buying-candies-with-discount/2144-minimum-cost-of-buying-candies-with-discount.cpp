class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int sum = 0, f = 0;
        for(int ind = cost.size() - 1; ind >= 0; --ind){
            if(f == 2){
                f = 0;
                continue;
            }
            ++f;
            sum += cost[ind];
        }
        return sum;
    }
};