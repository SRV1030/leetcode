class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> numToIndex;
        for(int index = 0; index < nums.size(); ++index)
            numToIndex[nums[index]].push_back(index);
        int res = INT_MAX;
        for(auto& [num, indices] : numToIndex){
            if(indices.size() < 3)
                continue;
            for(int ind = 0; ind < indices.size() - 2; ++ind){
                res = min(res, 2 * (indices[ind + 2] - indices[ind]));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};