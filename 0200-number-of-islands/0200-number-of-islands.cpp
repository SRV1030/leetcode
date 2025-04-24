class Solution {
public:
    int rowSize,colSize;
    vector<vector<int>>directions= {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& grid,int row,int col){
        if(min(row,col)<0 || row>=rowSize || col>=colSize || grid[row][col]!='1') return;
        grid[row][col] = '$';
        for(auto&dir:directions)
            dfs(grid,row+dir[0],col+dir[1]);
    }
    int numIslands(vector<vector<char>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        int islands = 0;
        for(int row=0;row<rowSize;row++)
            for(int col=0;col<colSize;col++)
                if(grid[row][col]=='1'){
                    dfs(grid,row,col);
                    islands++;
                }
        return islands;
    }
};