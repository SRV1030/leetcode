class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1 && nums.size() > 1)
            return true;
        int start = 1, nextStart = k + 1, len = 1;
        for(; nextStart < nums.size(); ++start, ++nextStart){
            if(nums[start] > nums[start - 1] && nums[nextStart] > nums[nextStart - 1])
                ++len;
            else
                len = 1;
            if(len == k)
                return true;
        }
        return len == k;
    }
};