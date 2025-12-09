class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> prevFrequency, nextFrequency;
        long long tripletCount = 0;
        const int MOD = 1e9 + 7;
        for(auto& num: nums) ++nextFrequency[num];
        for(auto& num: nums){
            --nextFrequency[num];
            long long triplet = (1ll * prevFrequency[num * 2] * nextFrequency[num * 2]) % MOD;
            tripletCount  = (tripletCount + triplet) % MOD;
            ++prevFrequency[num];
        }
        return tripletCount;
    }
};