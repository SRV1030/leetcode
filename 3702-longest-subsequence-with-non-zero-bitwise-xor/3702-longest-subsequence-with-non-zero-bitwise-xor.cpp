class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0, zero = 0;
        for(auto& num : nums){
            xr ^= num;
            if(num)
                zero = 1;
        }
        if(xr)
            return nums.size();
        return zero ? nums.size() - 1 : 0;
    }
};