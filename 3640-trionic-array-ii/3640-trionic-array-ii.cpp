class Solution {
    long long NEG_INF = -1e18;
    vector<vector<long long>> memo;
    int size;
public:
    long long solve(vector<int>& nums, int index, int state){
        if(index == size)
            return state == 3 ? 0 : NEG_INF;
        long long& res = memo[index][state];

        if(res == LONG_MIN){
            res = NEG_INF;
            if(state == 0)
                res = solve(nums, index + 1, 0);
            
            if(state == 3)
                res = nums[index];
            
            if(index + 1 < size){
                if(state == 0 && nums[index] < nums[index + 1])
                    res = max(res, nums[index] + solve(nums, index + 1, 1));
                else if(state == 1){
                    if(nums[index] < nums[index + 1])
                        res = max(res, nums[index] + solve(nums, index + 1, 1));
                    else if (nums[index] > nums[index + 1])
                        res = max(res, nums[index] + solve(nums, index + 1, 2));
                }
                else if(state == 2){
                    if(nums[index] > nums[index + 1])
                        res = max(res, nums[index] + solve(nums, index + 1, 2));
                    else if (nums[index] < nums[index + 1])
                        res = max(res, nums[index] + solve(nums, index + 1, 3));
                }
                else if(state == 3 && nums[index] < nums[index + 1])
                    res = max(res, nums[index] + solve(nums, index + 1, 3));
            }
        }

        return res;
    }
    long long maxSumTrionic(vector<int>& nums) {
        size = nums.size();
        memo = vector<vector<long long>> (size, vector<long long>(4, LONG_MIN));
        return solve(nums, 0, 0);
    }
};