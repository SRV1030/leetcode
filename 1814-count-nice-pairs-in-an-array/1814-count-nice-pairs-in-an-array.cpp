class Solution {
    int MOD = 1e9 + 7;
public:
    int reverseNum(int num){
        int rev = 0;
        while(num){
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, int> frequemcy;
        long long count = 0;
        for(auto& num : nums){
            long long diff = num - reverseNum(num);
            count += frequemcy[diff];
            frequemcy[diff]++;
        }
        return count % MOD;
    }
};