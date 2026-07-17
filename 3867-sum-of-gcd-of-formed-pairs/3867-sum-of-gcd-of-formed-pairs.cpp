class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> prefixGcd(nums.size());
        int mx = 0;
        for(int ind = 0; ind < nums.size(); ++ind){
            mx = max(mx, nums[ind]);
            prefixGcd[ind] = __gcd(mx, nums[ind]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long res = 0;
        int l = 0, r = prefixGcd.size() - 1;
        while(l < r){
            res += __gcd(prefixGcd[l++], prefixGcd[r--]); 
        }
        return res;
    }
};