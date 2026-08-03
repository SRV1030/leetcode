class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        vector<int> mp(k);
        mp[0] = 1;
        for(auto& num : nums){
            sum += num;
            int rem = sum % k;
            if(rem < 0)
                rem += k;
            res += mp[rem];
            mp[rem]++;
        }
        return res;
    }
};