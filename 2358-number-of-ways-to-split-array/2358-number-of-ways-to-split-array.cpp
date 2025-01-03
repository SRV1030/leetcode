class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long l=0,r=0;
        for(auto&i:nums)r+=i;
        int c=0;
        for(int i=0;i<nums.size()-1;++i){
            l+=nums[i];
            r-=nums[i];
            if(l>=r)++c;
        }
        return c;
    }
};