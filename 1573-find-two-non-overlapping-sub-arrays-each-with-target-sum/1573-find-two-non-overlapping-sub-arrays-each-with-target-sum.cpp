class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        if(!arr.size()) return 0;
        int n=arr.size(),sm=0,ans=n+1,lft=n+1;
        map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            mp[sm]=i;
        }
        sm=0;
        for(int i=0;i<n;i++){
            sm+=arr[i];
            int l=sm-target,r=sm+target;
            if(mp.count(l))lft=min(lft,i-mp[l]);
            if(mp.count(r))ans=min(ans,lft+mp[r]-i);
        }
        return ans==n+1?-1:ans;
    }
};