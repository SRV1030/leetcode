class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long l=0,r=0;
        for(auto&i:nums)r+=i;
        int c=0;
        for(int i=0;i<nums.size()-1;++i){
            r-=nums[i];
            l+=nums[i];
            if((r-l)%2==0)++c;
        }
        return c;
    }
};