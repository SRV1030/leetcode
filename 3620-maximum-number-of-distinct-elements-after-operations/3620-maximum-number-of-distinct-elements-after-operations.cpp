class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int prev = INT_MIN;
        int unique = 0;
        for(auto& num : nums){
            int cur = min(max(num - k, prev + 1), num + k);
            if(cur != prev){
                prev= cur;
                ++unique;
            }
        }
        return unique;
    }
};