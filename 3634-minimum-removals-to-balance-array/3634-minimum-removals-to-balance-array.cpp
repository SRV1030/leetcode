class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX, size = nums.size();
        for(int left = 0, right = 0; left < size; ++left){
            while(right < size && 1ll * nums[left] * k >= nums[right]){
                ++right;
            }
            res = min(res, size - (right - left));
        }
        return res;
    }
};