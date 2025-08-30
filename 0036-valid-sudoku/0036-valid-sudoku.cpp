class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), block(9);
        for(int row = 0; row < 9; ++row){
            for(int col = 0; col < 9; ++col){
                if(board[row][col] != '.'){
                    int blockIndex = row / 3 * 3 + col / 3;
                    if(rows[row].count(board[row][col]) || cols[col].count(board[row][col]) || block[blockIndex].count(board[row][col]))
                        return false;
                    rows[row].insert(board[row][col]);
                    cols[col].insert(board[row][col]);
                    block[blockIndex].insert(board[row][col]);
                }
            }
        }
        return true;
    }
};