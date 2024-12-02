class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=nums[0],cursm=0;
        for(auto&i:nums){
            cursm+=i;
            if(cursm>mx)mx=cursm;
            if(cursm<0)cursm=0;
        }
        return mx;
    }
};