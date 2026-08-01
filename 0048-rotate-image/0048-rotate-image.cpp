class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int row = 0; row < size / 2; ++row){
            for(int col = row; col < size - row - 1; ++col){
                int storage = matrix[row][col];
                matrix[row][col] = matrix[size - col - 1][row];
                matrix[size - col - 1][row] = matrix[size - row - 1][size - col - 1];
                matrix[size - row - 1][size - col - 1] = matrix[col][size - row - 1];
                matrix[col][size - row - 1] = storage; 
            }
        }
    }
};