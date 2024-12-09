class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ps{0};
        for(int i=1;i<size(nums);++i)ps.push_back(ps.back()+(nums[i-1]%2==nums[i]%2));
        vector<bool> ans;
        for(auto&q:queries) ans.push_back(ps[q[0]]==ps[q[1]]);
        return ans;
    }
};