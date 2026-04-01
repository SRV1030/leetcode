class Solution {
    int memo[301][301];
public:
    int solve(vector<int>& nums, int low, int high){
        if(low > high)
            return 0;
        
        int& res = memo[low][high];

        if(res == -1){
            res = -1e9;
            for(int ind = low; ind <= high; ++ind){
                int temp = solve(nums, low, ind - 1) + nums[low - 1] * nums[ind] * nums[high + 1] + solve(nums, ind + 1, high);
                res = max(res, temp);
            }
        }

        return res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(memo, -1, sizeof(memo));
        return solve(nums, 1, nums.size() - 2);
    }
};