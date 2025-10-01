class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return false;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int index = 0; index < nums.size(); ++index){
            sum += nums[index];
            sum %= k;
            if(mp.count(sum) && abs(index - mp[sum]) > 1)
                return true;
            if(!mp.count(sum))
                mp[sum] = index;
        }
        return false;
    }
};