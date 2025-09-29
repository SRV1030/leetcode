class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool hasOne = false;
        int sizeOfNum = nums.size();
        for(auto& num: nums){
            if(num == 1)
                hasOne = true;
            else if(num <= 0 || num > sizeOfNum)
                num = 1;
        }
        if(!hasOne)
            return 1;
        for(auto& num: nums)
            if(nums[abs(num) - 1] > 0)
                nums[abs(num) - 1] = - nums[abs(num) - 1];
        for(int index = 0; index < sizeOfNum; index++)
            if(nums[index] > 0) 
                return index + 1;
        return sizeOfNum + 1;
    }
};