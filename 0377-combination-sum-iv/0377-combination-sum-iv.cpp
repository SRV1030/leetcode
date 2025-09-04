class Solution {
    vector<int> memory;
public:
    int countCombos(vector<int>& nums, int target){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        int& count = memory[target];
        if(count == -1){
            count = 0;
            for(auto& num : nums)
                count += countCombos(nums, target - num);
        }
        return count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memory = vector<int> (target + 1, -1);
        return countCombos(nums, target);
    }
};