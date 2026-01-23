class Solution {
    vector<int> memo;
    int size, powerSetSize, target;
public:
    bool isPos(vector<int>& nums, int mask, int sum){
        if(mask == powerSetSize)
            return sum == 0;
        if(memo[mask] != -1)
            return memo[mask];

        for(int index = 0; index < size; ++index){
            if(!(mask & (1 << index))){
                if(sum + nums[index] > target)
                    continue;
                int nextSum = (sum + nums[index] == target) ? 0 : sum + nums[index];
                if(isPos(nums, mask | (1 << index), nextSum))
                    return memo[mask] = 1;
            }
        }
        return memo[mask] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for(auto& num : nums)
            total += num;
        if(total % k)
            return false;
        target = total / k;
        size = nums.size();
        powerSetSize = (1 << size) - 1;
        memo = vector<int> (powerSetSize + 1, -1);
        return isPos(nums, 0, 0);
    }
};