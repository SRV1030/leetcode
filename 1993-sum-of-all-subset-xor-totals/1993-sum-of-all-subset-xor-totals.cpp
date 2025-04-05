class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        long long xrSm=0,size=nums.size(),total=1<<size;
        for(int i=1;i<total;i++){
            long long xr=0;
            for(int b=0;b<size;b++){
                if(i&(1<<b))xr^=nums[b];
            }
            xrSm+=xr;
        }
        return xrSm;
    }
};