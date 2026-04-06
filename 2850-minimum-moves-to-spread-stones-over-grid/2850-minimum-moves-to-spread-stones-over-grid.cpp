class Solution {
    int size = 3;
    bool checkSpred(vector<vector<int>>& grid){
        for(int row = 0; row < size; ++ row)
            for(int col = 0; col < size; ++col)
                if(grid[row][col] != 1)
                    return false;
        return true;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        if(checkSpred(grid))
            return 0;
        int minMove = INT_MAX;
        for(int row = 0; row < size; ++ row)
            for(int col = 0; col < size; ++col){
                if(grid[row][col] == 0){
                    for(int nrow = 0; nrow < size; ++nrow)
                        for(int ncol = 0; ncol < size; ++ncol){
                            if(grid[nrow][ncol] > 1){
                                int dist = abs(nrow - row) + abs(ncol - col);
                                --grid[nrow][ncol];
                                ++grid[row][col];
                                minMove = min(minMove, dist + minimumMoves(grid));
                                ++grid[nrow][ncol];
                                --grid[row][col];
                            }
                        }
                }
            }
        return minMove;
    }
};