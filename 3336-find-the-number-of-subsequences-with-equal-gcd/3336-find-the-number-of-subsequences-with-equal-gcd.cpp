class Solution {
    int memo[201][201][201];
    const int MOD = 1e9 + 7;
public:
    int solve(vector<int>& nums, int ind, int g1, int g2){
        if(ind  == nums.size())
            return g1 && g1 == g2;
        int& count = memo[ind][g1][g2];
        if(count == -1){
            count = solve(nums, ind + 1, g1, g2);
            int ng1 = g1 ? __gcd(g1, nums[ind]) : nums[ind];
            int ng2 = g2 ? __gcd(g2, nums[ind]) : nums[ind];
            count = (count % MOD + solve(nums, ind + 1, ng1, g2) % MOD) % MOD;
            count = (count % MOD + solve(nums, ind + 1, g1, ng2) % MOD) % MOD;
        }
        return count;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(nums, 0, 0, 0);
    }
};