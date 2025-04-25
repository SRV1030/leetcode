class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0,  equals = 0;
        unordered_map<int,long long> mapRemainder;
        mapRemainder[0] = 1;
        for(auto& num:nums){
            equals += (num % modulo == k);
            int remainder = equals % modulo;
            int needed = (remainder - k + modulo) % modulo;
            count += mapRemainder[needed];
            mapRemainder[remainder]++;
        }
        return count;
    }
};