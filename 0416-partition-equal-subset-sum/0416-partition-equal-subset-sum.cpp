class Solution {
    vector<vector<int>> memo;
public:
    bool check(vector<int>& nums, int total, int index){
        if(total == 0)
            return true;
        if(index >= nums.size())
            return false;
        int& res = memo[index][total];
        if(res == -1){
            res = check(nums, total, index + 1);
            if(nums[index] <= total)
                res |= check(nums, total - nums[index], index + 1);
        }
        return res;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto& num : nums)
            total += num;
        if(total % 2)
            return false;
        total /= 2;
        memo = vector<vector<int>> (nums.size(), vector<int>(total + 1, -1));
        return check(nums, total, 0);
    }
};