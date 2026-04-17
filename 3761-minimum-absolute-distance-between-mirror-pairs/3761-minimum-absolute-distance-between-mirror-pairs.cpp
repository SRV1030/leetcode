class Solution {
public:
    int reverse(int num) {
        int res = 0;
        while (num > 0) {
            res = res * 10 + (num % 10);
            num /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mn = INT_MAX;

        for(int i = 0; i < nums.size(); ++i){
            auto it = mp.find(nums[i]);
            if(it != mp.end())
                mn = min(mn, i - it->second);

            mp[reverse(nums[i])] = i;
        }
        return mn == INT_MAX ? -1 : mn;
    }
};