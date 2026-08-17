class Solution {
    int size;
    int memo[501][501];
    vector<int> prefixSum;
public:
    int solve(vector<int>& stoneValue, int left, int right){
        if(left >= right){
            return 0;
        }
        int& res = memo[left][right];
        if(res == -1){
            res = 0;
            for(int mid = left; mid < right; ++mid){
                int leftSum = prefixSum[mid + 1] - prefixSum[left];
                int rightSum = prefixSum[right + 1] - prefixSum[mid + 1];
                if(leftSum > rightSum)
                    res = max(res, rightSum + solve(stoneValue, mid + 1, right));
                else if(leftSum < rightSum)
                    res = max(res, leftSum + solve(stoneValue, left, mid));
                else
                    res = max(res, max(leftSum + solve(stoneValue, left, mid), rightSum + solve(stoneValue, mid + 1, right)));
            }
        }
        return res;
    }

    int stoneGameV(vector<int>& stoneValue) {
        memset(memo, -1, sizeof(memo));
        size = stoneValue.size();
        prefixSum.resize(size + 1);
        for(int ind = 0; ind < size; ++ind)
            prefixSum[ind + 1] = prefixSum[ind] + stoneValue[ind];
        return solve(stoneValue, 0, size - 1);
    }
};