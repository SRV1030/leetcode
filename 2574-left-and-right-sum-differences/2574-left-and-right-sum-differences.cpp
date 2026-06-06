class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        for(auto& num : nums){
            right -= num;
            res.push_back(abs(right - left));
            left += num;
        }
        return res;
    }
};