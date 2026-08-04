class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int size = nums.size();
        vector<long long> ans(size);
        unordered_map<int, vector<int>> indicesMap;
        for(int index = 0; index < size; ++index)
            indicesMap[nums[index]].push_back(index);
        for(auto&[_, indices] : indicesMap){
            long long sum = 0, ls = 0, rs = 0;
            for(auto& ind : indices)
                sum += ind;
            for(int i = 0; i < indices.size(); ++i){
                rs = sum - ls - indices[i];
                long long left = 1ll * indices[i] * i- ls;
                long long right = rs - 1ll * indices[i] * (indices.size() - i -1);
                ans[indices[i]] = left + right;
                ls += indices[i];
            }
        }
        return ans;
    }
};