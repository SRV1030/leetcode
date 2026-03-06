class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        if(nums.size() == 1)
            return {-1, -1};
        map<int, int> mp;
        for(auto& num : nums)
            mp[num]++;
        for(auto&[key, value] : mp)
            for(auto&[key2, value2] : mp){
                if(key != key2 && value != value2)
                    return {key, key2};
            }
        return {-1, -1};
    }
};