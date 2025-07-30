class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = 0, length = 0, maxLength = 0;
        for(auto& num: nums){
            if(num > maxNum){
                maxNum = num;
                length = maxLength = 0;
            }
            if(num == maxNum)
                ++length;
            else
                length = 0;
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};