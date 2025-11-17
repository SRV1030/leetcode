class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;
        for (int index = 0; index < nums.size(); ++index) {
            if (nums[index] == 1) {
                if (prev != -1 && index - prev - 1 < k)
                    return false;
                prev = index;
            }
        }
        return true;
    }
};