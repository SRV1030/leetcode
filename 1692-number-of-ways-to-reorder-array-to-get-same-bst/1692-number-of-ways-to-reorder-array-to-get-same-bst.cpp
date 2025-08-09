class Solution {
    vector<vector<int>> combinations;
    const int MOD = 1e9 + 7; 
    int size;
public:

    void fillAllPossibleCombinations(){
        int maxNum = size;
        combinations = vector<vector<int>> (maxNum + 1, vector<int>(maxNum + 1));
        for(int num = 0; num <= maxNum; ++num){
            combinations[num][0] = combinations[num][num] = 1;
            for(int k = 1; k < num; ++k){
                combinations[num][k] = (combinations[num - 1][k] + combinations[num - 1][k - 1]) % MOD;
            }
        }
    }
    int allPossibleBSTs(vector<int>& nums){
        if(nums.size() <= 1)
            return 1;
        int root = nums[0];
        vector<int> leftSubTree, rightSubTree;
        for(auto& num: nums){
            if(num < root)
                leftSubTree.push_back(num);
            else if(num > root)
                rightSubTree.push_back(num);
        }
        int leftPossibleBSTs = allPossibleBSTs(leftSubTree) % MOD;
        int rightPossibleBSTs = allPossibleBSTs(rightSubTree) % MOD;

        int interLeaveWays = (combinations[leftSubTree.size() + rightSubTree.size()][rightSubTree.size()]) % MOD;
        return (1ll * ((1ll * leftPossibleBSTs * rightPossibleBSTs) % MOD) * interLeaveWays) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        size = nums.size();
        fillAllPossibleCombinations();
        return ((allPossibleBSTs(nums) - 1 )% MOD) % MOD;
    }
};

/**
     * Computes C(n, k) = n! / (k! * (n-k)!) modulo `mod`
     * using Pascal's triangle identity:
     *   C(n, k) = C(n-1, k-1) + C(n-1, k)
     * with base cases:
     *   C(n, 0) = C(n, n) = 1
     */

    //  https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/solutions/819858/c-python-question-explained-then-detailed-solution-short-fast-readable/