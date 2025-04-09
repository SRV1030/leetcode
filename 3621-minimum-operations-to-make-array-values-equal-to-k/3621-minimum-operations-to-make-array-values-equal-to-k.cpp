class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end()),
            unique = set<int>(nums.begin(), nums.end()).size();
        return mn < k ? -1 : mn == k ? unique - 1 : unique;
    }
};