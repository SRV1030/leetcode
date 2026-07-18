class Solution {
public:
    int findGCD(vector<int>& nums) {
        int sm = INT_MAX, gr = INT_MIN;
        for(int num : nums){
            sm = min(num, sm);
            gr = max(num, gr);
        }
        return __gcd(sm, gr);
    }
};