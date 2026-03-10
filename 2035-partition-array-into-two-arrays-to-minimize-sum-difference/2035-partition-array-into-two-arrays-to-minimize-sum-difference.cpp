class Solution {
public:
    vector<vector<int>> findAllSubsetSum(vector<int>& nums, int leftIndex,int rightIndex){
        int lengthOfArray = rightIndex - leftIndex + 1;
        vector<vector<int>> subsetSums(lengthOfArray + 1);
        int highestMask = (1 << lengthOfArray);
        for(int mask = 0; mask < highestMask ; mask++){
            int subsetSum = 0, sizeOfSubset = 0;
            for(int index = 0; index < lengthOfArray; index++){
                if(mask & (1 << index)){
                    subsetSum += nums[leftIndex + index];
                    ++sizeOfSubset;
                }
            }
            subsetSums[sizeOfSubset].push_back(subsetSum);
        }
        return subsetSums;
    }
    int minimumDifference(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int sizeOfNums = nums.size(), halfOfSizeOfNums = sizeOfNums / 2 ;
        int targetSum = totalSum / 2;

        vector<vector<int>> leftSubsetSums = findAllSubsetSum(nums, 0 , halfOfSizeOfNums - 1);
        vector<vector<int>> rightSubsetSums = findAllSubsetSum(nums, halfOfSizeOfNums , sizeOfNums - 1);
        int minDifference = INT_MAX;
        for(int index = 0; index <= halfOfSizeOfNums; index++){
            auto rightSums = rightSubsetSums[halfOfSizeOfNums - index];
            sort(begin(rightSums), end(rightSums));

            for(int leftSum: leftSubsetSums[index]){
                int targetRightSum = targetSum - leftSum;
                auto iteratorOfRightSum = lower_bound(begin(rightSums), end(rightSums), targetRightSum);
                if(iteratorOfRightSum != end(rightSums))
                    minDifference = min(minDifference, abs(totalSum - (2 * (*iteratorOfRightSum + leftSum))));
            }
        }
        return minDifference;
    }
};