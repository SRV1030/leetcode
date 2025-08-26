class NumMatrix {
    vector<vector<int>> sumMatrix;
    int rows, cols;
public:
    int getValue(int row, int col){
        if(min(row, col) < 0)
            return 0;
        return sumMatrix[row][col];
    }
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        sumMatrix = vector<vector<int>> (rows, vector<int>(cols));
        for(int row = 0; row < rows; ++row)
            for(int col = 0; col < cols; ++col){
                sumMatrix[row][col] = matrix[row][col] + getValue(row - 1, col) + getValue(row, col - 1) - getValue(row - 1, col - 1);
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getValue(row2, col2)  - getValue(row2, col1 - 1) - getValue(row1 - 1, col2) + getValue(row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */