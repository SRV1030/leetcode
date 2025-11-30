class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sm=0,csm=0,n=size(nums),mn=n;
        unordered_map<long long,int> mp;
        mp[0]=-1;
        for(auto&i:nums)sm+=i;
        sm%=p;
        if(!sm) return 0;
        for(long long i=0;i<n;++i){
            csm = (csm+nums[i])%p;
            int rem = (csm-sm+p)%p;
            if(mp.count(rem))mn=min(mn,i-mp[rem]);
            mp[csm]=i;
        }
        return mn==n?-1:mn;
    }
};