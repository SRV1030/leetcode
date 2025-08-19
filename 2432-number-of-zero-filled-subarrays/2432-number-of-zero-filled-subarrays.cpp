class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, streak = 0;
        for(auto& num : nums){
            streak = (num == 0) ? streak + 1 : 0;
            count += streak;
        }
        return count;
    }
};