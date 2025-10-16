class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int> (n));
        int row = 0, col = 0, rowSize = n - 1, colSize = n - 1;
        int val = 1;
        while(row <= rowSize && col <= colSize){
            for(int k = col; k <= colSize; ++k)
                result[row][k] = val++;
            ++row;
            for(int k = row; k <= rowSize; ++k)
                result[k][colSize] = val++;
            --colSize;
            if(row <= rowSize){
                for(int k = colSize; k >= col; --k)
                    result[rowSize][k] = val++;
                --rowSize;
            }
            if(col <= colSize){
                for(int k = rowSize; k >= row; --k)
                    result[k][col] = val++;
                ++col;
            }
        }
        return result;
    }
};