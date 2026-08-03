class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        for(auto& num : nums){
            sum += num;
            int rem = sum % k;
            if(rem < 0)
                rem += k;
            if(mp.count(rem))
                res += mp[rem];
            mp[rem]++;
        }
        return res;
    }
};