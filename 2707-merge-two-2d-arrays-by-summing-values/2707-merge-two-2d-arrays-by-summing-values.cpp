class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<int> allNums(1000 + 1);
        for (int i = 0; i < nums1.size() || i < nums2.size(); ++i) {
            if (i < nums1.size())
                allNums[nums1[i][0]] += nums1[i][1];
            if (i < nums2.size())
                allNums[nums2[i][0]] += nums2[i][1];
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= 1000; ++i)
            if (allNums[i])
                ans.push_back({i, allNums[i]});
        return ans;
    }
};