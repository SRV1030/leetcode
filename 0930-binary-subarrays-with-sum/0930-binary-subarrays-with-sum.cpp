class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result = 0, count = 0;
        int size = nums.size();
        vector<int> memory(size + 1);
        memory[0] = 1;
        for(auto& num : nums){
            count += num;
            if(count >= goal){
                result += memory[count - goal];
            }
            memory[count]++;
        }
        return result;
    }
};