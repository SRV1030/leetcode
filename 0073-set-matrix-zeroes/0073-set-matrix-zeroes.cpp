class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = false;
        int rowSize = matrix.size(), colSize = matrix[0].size();
        for(int row = 0; row < rowSize; ++row){
            if(!matrix[row][0])
                col0 = true;
            for(int col = 1; col < colSize; ++col){
                if(matrix[row][col] == 0)
                    matrix[row][0] = matrix[0][col] = 0;
            }
        }
        for(int row = rowSize - 1; row >= 0; row--){
            for(int col = colSize - 1;col >= 1; col--){
                if(matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] =  0;
            }
            if(col0)
                matrix[row][0] = 0;
        }
    }
};