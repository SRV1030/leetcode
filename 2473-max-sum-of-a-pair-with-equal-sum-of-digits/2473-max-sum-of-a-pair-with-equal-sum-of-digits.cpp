class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        sort(begin(nums),end(nums));
        int ans=-1;
        for(auto&i:nums){
            int x=i,sm=0;
            while(x){
                sm+=x%10;
                x/=10;
            }
            mp[sm].push_back(i);
            int n=mp[sm].size();
            if(n>=2)ans=max(ans,mp[sm][n-1]+mp[sm][n-2]);
        }
        return ans;
    }
};