class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int index = nums.size() - 2; index >= 0 ; --index){
            if(nums[index] < nums[index + 1]){
                int largeIndex = nums.size() - 1;
                while(index < largeIndex && nums[index] >= nums[largeIndex])
                    --largeIndex;
                swap(nums[index], nums[largeIndex]);
                reverse(nums.begin() + index + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};