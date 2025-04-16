class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long count = 0,kPairs = 0;
        unordered_map<int,int>mp;
        int l=0;
        for(int r=0;r<nums.size();r++){
            kPairs+=mp[nums[r]];
            mp[nums[r]]++;
            while(kPairs>=k){
                count+=(nums.size()-r);
                mp[nums[l]]--;
                kPairs-=mp[nums[l++]];
            }
        }
        return count;
    }
};