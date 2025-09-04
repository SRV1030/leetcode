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
        vector<unsigned long long> memory (target + 1);
        memory[0] = 1;
        for(int temp = 1; temp <= target; ++temp){
            for(auto& num : nums){
                if(num <= temp)
                    memory[temp] += memory[temp - num];
            }
        }
        return memory[target];
    }
};