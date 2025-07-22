class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixSum(size);
        unordered_map<int, int> indexMap;
        int leftIndex = - 1, maxSum = 0;
        for(int index = 0; index < size; ++index){
            prefixSum[index] = nums[index] + ((index > 0) ? prefixSum[index - 1] : 0);
            if(indexMap.count(nums[index])){
                leftIndex = max(leftIndex, indexMap[nums[index]]);
            }
            indexMap[nums[index]] = index;
            int sum = prefixSum[index] - ((leftIndex != - 1 ) ? prefixSum[leftIndex] : 0);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};