class Solution {
    vector<vector<int>> memory;
    int size;
    const int MOD = 1e9 + 7;
public:
    int subsetSum(vector<int> &powerArr, int target, int index){
        if(!target)
            return 1;
        if(index >= size)
            return 0;
        int& count = memory[index][target];
        if(count == -1){
            count = subsetSum(powerArr, target, index + 1) % MOD;
            if(target >= powerArr[index])
                count = (count + subsetSum(powerArr, target - powerArr[index], index + 1)) % MOD;
        }
        return count;
    }
    int numberOfWays(int n, int x) {
        vector<int> powerArr;
        for(int index = 1; pow(index, x) <= n; ++index)
            powerArr.push_back(pow(index, x));
        size = powerArr.size();
        memory = vector<vector<int>> (size, vector<int> (n + 1, -1));
        return subsetSum(powerArr, n, 0) % MOD;
    }
};