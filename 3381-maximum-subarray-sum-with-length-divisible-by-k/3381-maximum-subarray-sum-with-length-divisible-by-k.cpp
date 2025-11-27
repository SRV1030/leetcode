class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        long long maxSum = LLONG_MIN, currentSum = 0;
        vector<long long> kthSum(k + 1, LLONG_MAX / 2);
        kthSum[k - 1] = 0;
        for(int index = 0; index < size; ++index){
            currentSum += nums[index];
            maxSum = max(maxSum, currentSum - kthSum[index % k]);
            kthSum[index % k] = min(kthSum[index % k], currentSum);
        }
        return maxSum;
    }
};