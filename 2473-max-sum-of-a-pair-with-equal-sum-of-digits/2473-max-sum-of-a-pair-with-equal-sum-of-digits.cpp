class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(auto&i:nums){
            int x=i,sm=0;
            while(x){
                sm+=x%10;
                x/=10;
            }
            if(mp.count(sm))ans=max(ans,mp[sm]+i);
            mp[sm]=max(mp[sm],i);
        }
        return ans;
    }
};