class Solution {
    vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    int rows, cols;
    vector<vector<int>> visited;

public:
    bool outOfBound(int r, int c){
        return r < 0 || c < 0 || r >= rows || c >= cols;
    }

    bool check(vector<vector<char>>& grid, int row, int col, int prow, int pcol, char ch){

        visited[row][col] = 1;

        for(auto &dir : directions){
            int nrow = row + dir[0];
            int ncol = col + dir[1];

            if(outOfBound(nrow,ncol))
                continue;

            if(grid[nrow][ncol] != ch)
                continue;

            if(nrow == prow && ncol == pcol)
                continue;

            if(visited[nrow][ncol])
                return true;

            if(check(grid,nrow,ncol,row,col,ch))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited.assign(rows, vector<int>(cols,0));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j]){
                    if(check(grid,i,j,-1,-1,grid[i][j]))
                        return true;
                }
            }
        }

        return false;
    }
};