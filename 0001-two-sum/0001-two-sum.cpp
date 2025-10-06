class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int index = 0; index < nums.size(); ++index){
            if(mp.count(target - nums[index]))
                return {mp[target - nums[index]], index};
            mp[nums[index]] = index;
        }
        return {-1, -1};
    }
};