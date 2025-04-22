class Solution {
public:
    vector<vector<int>> validCombinations;
    void generateValidCombinations(vector<int>& candidates, int target,
                                   vector<int> subset, int index = 0,
                                   int currentSum = 0) {
        if (index >= candidates.size() || currentSum > target)
            return;
        if (currentSum == target) {
            validCombinations.push_back(subset);
            return;
        }
        subset.push_back(candidates[index]);
        generateValidCombinations(candidates, target, subset, index,
                                  currentSum + candidates[index]);
        subset.pop_back();
        generateValidCombinations(candidates, target, subset, index + 1,
                                  currentSum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        generateValidCombinations(candidates, target, {});
        return validCombinations;
    }
};