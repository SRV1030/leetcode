class Solution {
    int dimension;
    vector<vector<string>> allValidQueenPlacements;
    vector<string> board;
public:
    bool canPlaceQueen(int& row, int& column){
        for(int colIndex = 0; colIndex < column; colIndex++)
            if(board[row][colIndex] == 'Q')
                return false;
        for(int colIndex = column, rowIndex = row; colIndex >= 0 && rowIndex >= 0; --colIndex, --rowIndex)
            if(board[rowIndex][colIndex] == 'Q')
                return false;
        for(int colIndex = column, rowIndex = row; colIndex >= 0 && rowIndex < dimension; --colIndex, ++rowIndex)
            if(board[rowIndex][colIndex] == 'Q')
                return false;
        return true;
    }
    void generateAllQueens(int column){
        if(column == dimension){
            allValidQueenPlacements.push_back(board);
            return;
        }
        for(int row = 0; row < dimension; row++)
            if(canPlaceQueen(row, column)){
                board[row][column] = 'Q';
                generateAllQueens(column + 1);
                board[row][column] = '.';
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        dimension = n;
        board = vector<string>(dimension, string(n, '.'));
        generateAllQueens(0);
        return allValidQueenPlacements;
    }
};