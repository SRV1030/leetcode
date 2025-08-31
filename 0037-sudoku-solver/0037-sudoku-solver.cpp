class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char currentDigit){
        for(int index = 0; index < 9; index++){
            if(board[index][col] == currentDigit || board[row][index] == currentDigit || board[3 * (row / 3) + index / 3][3 * (col / 3) + index % 3] == currentDigit)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row = 0; row < 9; row++)
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char digit = '1'; digit <= '9'; digit++){
                        if(isValid(board, row, col, digit)){
                            board[row][col] = digit;
                            if(solve(board))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};