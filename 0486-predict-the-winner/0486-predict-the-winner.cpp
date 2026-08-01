class Solution {
    int memo[23][23];
public:
    int solve(vector<int>& nums, int i, int j){
        if(i > j)
            return 0;
        int& res = memo[i][j];
        if(res == -1){
            res = nums[i] + min(solve(nums, i + 1, j - 1), solve(nums, i + 2, j));
            res = max(res, nums[j] + min(solve(nums, i + 1, j - 1), solve(nums, i , j - 2)));
        }
        return res;
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        int p1Score = solve(nums, 0, nums.size() - 1);
        int total = 0;
        for(auto& num : nums)
            total += num;
        return 2 * p1Score - total >= 0;
    }
};