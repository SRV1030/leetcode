class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int size = nums.size();
        frequency.reserve(size);
        int len = 0;
        for(int left = 0, right = 0; right < size; ++right){
            int &fr = frequency[nums[right]];
            ++fr;
            while(fr > k){
                --frequency[nums[left++]];
            }
            len = max(len , right - left + 1);
        }
        return len;
    }
};