class Solution {
public:
    int subArraysWithAtMostSum(vector<int>& nums, int k){
        if(!k)
            return 0;
        unordered_map<int, int> frequencyMap;
        int sizeOfNums = nums.size();
        int countSubArrays = 0;
        for(int leftIndex = 0, rightIndex = 0; rightIndex < sizeOfNums; rightIndex++){
            frequencyMap[nums[rightIndex]]++;
            while(frequencyMap.size() > k){
                if(frequencyMap[nums[leftIndex]] == 1)
                    frequencyMap.erase(nums[leftIndex]);
                else 
                    frequencyMap[nums[leftIndex]]--;
                leftIndex++;
            }
            countSubArrays += (rightIndex - leftIndex + 1);
        }
        return countSubArrays;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArraysWithAtMostSum(nums, k) - subArraysWithAtMostSum(nums, k - 1); 
    }
};