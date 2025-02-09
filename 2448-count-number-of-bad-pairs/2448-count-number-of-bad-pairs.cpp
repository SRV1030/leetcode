class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long gp=0,n=nums.size();
        for(int i=0;i<nums.size();++i){
            int k = nums[i]-i;
            gp+=mp[k];
            mp[k]++;
        }
        return n*(n-1)/2-gp;
    }
};