class Solution {
    int rowSize, colSize;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    void mark(int row, int col, vector<vector<char>>& board){
        if(min(row, col) < 0 || row >= rowSize || col >= colSize || board[row][col] != 'O')
            return;
        board[row][col] = '$';
        for(auto& [x, y] : directions)
            mark(row + x, col + y, board);
    }
    void solve(vector<vector<char>>& board) {
        rowSize = board.size(), colSize = board[0].size();
        for(int row = 0; row < rowSize; ++row){
            mark(row, 0, board);
            mark(row, colSize - 1, board);
        }
        for(int col = 0; col < colSize; ++col){
            mark(0, col, board);
            mark(rowSize - 1, col, board);
        }
        for(int row = 0; row < rowSize; ++row){
            for(int col = 0; col < colSize; ++col){
                if(board[row][col] == '$')
                    board[row][col] = 'O';
                else if (board[row][col] == 'O')
                    board[row][col] = 'X';
            }
        }
    }
};