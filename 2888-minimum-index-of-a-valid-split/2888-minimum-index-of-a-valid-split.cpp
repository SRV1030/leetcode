class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> fmp, tfmp;
        for (auto& i : nums)
            fmp[i]++;
        for (int i = 0; i < n; i++) {
            tfmp[nums[i]]++;
            if ((tfmp[nums[i]] * 2) > (i + 1) &&
                (((fmp[nums[i]] - tfmp[nums[i]]) * 2 )> (n - i - 1)))
                return i;
        }
        return -1;
    }
};