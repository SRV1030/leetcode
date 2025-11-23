class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int size = nums.size();
        vector<int> memory(3, INT_MIN);
        memory[0] = 0;
        for(int index = 0; index < size; ++index){
            vector<int> cache = memory;
            int mod = nums[index] % 3;
            for(int modIndex = 0; modIndex < 3; ++modIndex){
                cache[modIndex] = max(cache[modIndex] , nums[index] + memory[(mod + modIndex) % 3]);
            }
            memory = cache;
        }
        return memory[0];
    }
};