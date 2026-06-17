class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSubArraySum = nums[0];
        for(auto& num: nums){
            sum += num;
            maxSubArraySum = max(sum, maxSubArraySum);
            sum = max(sum, 0);
        }
        return maxSubArraySum;
    }
};