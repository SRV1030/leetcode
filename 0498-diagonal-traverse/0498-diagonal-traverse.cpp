class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int rows = mat.size(), cols = mat[0].size();
        int vectorSize = rows * cols;
        vector<int> diagonalOrder(vectorSize);
        for(int index = 0, row = 0, col = 0; index < vectorSize; ++index){
            diagonalOrder[index] = mat[row][col];
            if((row + col) % 2){
                if(row == rows - 1)
                    ++col;
                else if(col == 0)
                    ++row;
                else{
                    ++row;
                    --col;
                }
            }
            else{
                if(col == cols - 1)
                    ++row;
                else if(row == 0)
                    ++col;
                else{
                    --row;
                    ++col;
                }
            }
        }
        return diagonalOrder;
    }
};