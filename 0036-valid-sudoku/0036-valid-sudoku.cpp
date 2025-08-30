class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> rows[9], cols[9], block[9];
        for(int row = 0; row < 9; ++row){
            for(int col = 0; col < 9; ++col){
                if(board[row][col] != '.'){
                    int blockIndex = row / 3 * 3 + col / 3;
                    int numIndex = board[row][col] - '0';
                    if(rows[row][numIndex] || cols[col][numIndex] || block[blockIndex][numIndex])
                        return false;
                    rows[row][numIndex] = 1;
                    cols[col][numIndex] = 1;
                    block[blockIndex][numIndex] = 1;
                }
            }
        }
        return true;
    }
};