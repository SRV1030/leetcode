class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = 0, sum = 0, rem = 0, size = nums.size();
        for(auto& num : nums)
            sum += num;
        rem = sum - x;
        if(!rem)
            return size;
        for(int left = 0, right = 0, curSum = 0; right < size; ++right){
            curSum += nums[right];
            while(left < right && curSum > rem){
                curSum -= nums[left++];
            }
            if(curSum == rem)
                len = max(len, right - left + 1);
        }
        return len ? (size - len) : -1;
    }
};