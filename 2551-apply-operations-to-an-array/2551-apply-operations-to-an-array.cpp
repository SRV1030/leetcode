class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<size(nums)-1;++i){
            if(nums[i]==nums[i+1] && nums[i]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int nz=0;
        for(int i=0;i<size(nums);++i){
            if(nums[i]){
                nums[nz++]=nums[i];
            }
        }
        while(nz<nums.size())nums[nz++]=0;
        return nums;
    }
};