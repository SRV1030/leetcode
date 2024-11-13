class Solution {
public:
    long long lower_bound(vector<int>& nums,int s,int e,int k){
        while(s<=e){
            long long m = (s+e)>>1;
            if(nums[m]>=k) e = m-1;
            else s = m + 1;
        }
        return s;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(begin(nums),end(nums));
        for(int i=0;i<size(nums);++i){
            int lit = lower_bound(nums,i+1,size(nums)-1,lower-nums[i]);
            int uit = lower_bound(nums,i+1,size(nums)-1,upper-nums[i]+1);
            ans+=(uit-lit);
        }
        return ans;
    }
};