class Solution {
public:
    vector<vector<int>> validCombinations;
    void generateValidCombinations(vector<int>& candidates, int target,
                                   vector<int> subset, int index = 0,
                                   int currentSum = 0) {
        if (currentSum >= target) {
            if (currentSum == target)
                validCombinations.push_back(subset);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i - 1] == candidates[i])
                continue;
            subset.push_back(candidates[i]);
            generateValidCombinations(candidates, target, subset, i + 1,
                                      currentSum + candidates[i]);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        generateValidCombinations(candidates, target, {});
        return validCombinations;
    }
};