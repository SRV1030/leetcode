class Solution {
    long costNeeded(int num,int mask){
        int res = num;
        for(int i = 30; i >= 0; --i){
            long numB = (res >> i) & 1;
            long maskB = (mask >> i) & 1;
            if(maskB && !numB){
                res = ((res >> i) + 1) << i;
            }
        }
        return res;
    }
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int ans = 0;

        for(int bit = 30; bit >= 0; --bit){
            int mask = ans | (1 << bit);

            vector<long> cost;

            for(auto& num : nums)
                cost.push_back(costNeeded(num, mask) - num);
            
            sort(cost.begin(), cost.end());

            long incs = 0;
            for(int index = 0; index < m; ++index)
                incs += cost[index];
            
            if(incs <= k)
                ans = mask;
        }
        return ans;
    }
};