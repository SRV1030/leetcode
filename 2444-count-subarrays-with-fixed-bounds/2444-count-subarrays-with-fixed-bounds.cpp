class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans= 0, mnp=-1,mxp=-1,lb=-1;
        for(int i=0;i<size(nums);++i){
            if(nums[i]<minK || nums[i]>maxK) lb=i;
            if(nums[i]==minK)mnp=i;
            if(nums[i]==maxK)mxp=i;
            ans+=max(0ll,min(mxp,mnp)-lb);
        }
        return ans;
    }
};