class Solution {
public:
    int rob(vector<int>& nums, int low, int high){
        if(low > high)
            return 0;
        int back = 0, back2 = 0, result = 0;
        for(int index = low; index <= high; index++){
            result = max(nums[index] + back2, back);
            back2 = back;
            back = result;
        }
        return result;
    }
    int rob(vector<int>& nums) {
        int sizeOfNums = nums.size();
        if(sizeOfNums == 1) return nums[0];
        return max(rob(nums, 0, sizeOfNums - 2), rob(nums, 1, sizeOfNums - 1));
    }
};