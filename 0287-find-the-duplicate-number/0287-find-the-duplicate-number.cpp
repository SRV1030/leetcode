class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto&i:nums){
            if(nums[abs(i)-1]<0) return abs(i);
            nums[abs(i)-1] = -nums[abs(i)-1];
        }
        return 0;
    }
};