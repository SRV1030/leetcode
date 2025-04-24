class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>uniqueElements(nums.begin(),nums.end());
        unordered_map<int,int>elementToFrequencyMap;
        int completeSubarrays = 0;
        for(int l=0,r=0;r<nums.size();r++){
            elementToFrequencyMap[nums[r]]++;
            while(l<=r && elementToFrequencyMap.size() == uniqueElements.size()){
                completeSubarrays+=nums.size()-r;
                elementToFrequencyMap[nums[l]]--;
                if(!elementToFrequencyMap[nums[l]])elementToFrequencyMap.erase(nums[l]);
                l++;
            }
        }
        return completeSubarrays;
    }
};