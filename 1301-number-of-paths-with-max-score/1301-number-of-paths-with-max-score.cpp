class Solution {
    int rows, cols;
    vector<vector<vector<int>>> memo;
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {-1, -1}};
    const int MOD = 1e9 + 7;
public:
    vector<int> result(vector<string>& board, int row, int col){
        if(min(row, col) < 0 || max(row, col) >= rows || board[row][col] == 'X'){
            return {0, 0};
        }
        if(row == 0 && col == 0)
            return {0 , 1};
        vector<int>& res = memo[row][col];
        if(res[0] == -1){
            res[0] = res[1] = 0;
            for (auto &dir : directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];

                auto temp = result(board, nr, nc);

                if (!temp[1]) continue;

                if (!res[1] || temp[0] > res[0]) {
                    res = temp;
                } 
                else if (temp[0] == res[0]) {
                    res[1] = (res[1] + temp[1]) % MOD;
                }
            }
            if(res[1] && !(row == rows - 1 && col == cols - 1) && !(row == 0 && col == 0))
                res[0] = (res[0] + board[row][col] - '0') % MOD;
        }
        return res;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        rows = board.size();
        cols = board[0].size();
        memo = vector<vector<vector<int>>> (rows,vector<vector<int>>(cols, vector<int>(2, -1)));
        return result(board, rows - 1, cols - 1);
    }
};