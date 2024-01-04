class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto&i:nums)++mp[i];
        for(auto&[k,v]:mp){
            if(v==1) return -1;
            else ans+=ceil((double)v/3);
        }
        return ans;
    }
};