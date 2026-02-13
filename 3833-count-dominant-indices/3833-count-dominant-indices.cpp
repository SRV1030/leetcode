class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixSum(size + 1);
        for(int index = 0; index < size; ++index)
            prefixSum[index + 1] = prefixSum[index] + nums[index];
        
        int count = 0;
        for(int index = 0; index < size - 1; ++index){
            int avg = (prefixSum[size] - prefixSum[index + 1]);
            if((nums[index] * (size - index - 1)) > avg)
                ++count;
        }

        return count;
    }
};