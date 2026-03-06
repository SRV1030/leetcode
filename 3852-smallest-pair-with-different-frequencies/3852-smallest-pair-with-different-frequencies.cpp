class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        if(nums.size() == 1)
            return {-1, -1};
        map<int, int> mp;
        for(auto& num : nums)
            mp[num]++;
        int prev = -1, fr = -1;
        for(auto&[key, value] : mp){
            if(prev == -1){
                prev = key;
                fr = value;
            }
            else if(value != fr)
                return {prev, key};
        }
        return {-1, -1};
    }
};