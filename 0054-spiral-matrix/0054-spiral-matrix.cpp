class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = 0, col = 0, rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;
        vector<int> spiral;
        while(row <= rowEnd && col <= colEnd){
            for(int index = col; index <= colEnd; ++index)
                spiral.push_back(matrix[row][index]);
            ++row;
            for(int index = row; index <= rowEnd; ++index)
                spiral.push_back(matrix[index][colEnd]);
            --colEnd;
            if(row <= rowEnd){
                for(int index = colEnd; index >= col; --index)
                    spiral.push_back(matrix[rowEnd][index]);
                --rowEnd;
            }
            if(col <= colEnd){
                for(int index = rowEnd; index >= row; --index)
                    spiral.push_back(matrix[index][col]);
                ++col;
            }
        }
        return spiral;
    }
};