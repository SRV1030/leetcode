class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> prefix(rows, vector<int>(cols, 1)), answer = prefix;
        long long pref = 1, suff = 1;
        const int MOD = 12345;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                prefix[row][col] = pref;
                pref = (pref * grid[row][col]) % MOD;
            }
        }

        for(int row = rows - 1; row >= 0; --row){
            for(int col = cols - 1; col >= 0; --col){
                answer[row][col] = (prefix[row][col] * suff) % MOD;
                suff = (grid[row][col] * suff) % MOD;
            }
        }

        return answer;
    }
};