class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0, negatives = 0, minVal = INT_MAX;
        for(auto& row : matrix){
            for(auto& col : row){
                long long num = abs(col);
                sum += num;
                minVal = min(minVal, num);
                if(col < 0)
                    ++negatives;
            }
        }
        return negatives % 2 ? sum - 2 * minVal : sum;
    }
};