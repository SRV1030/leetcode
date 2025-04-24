class Solution {
public:
    int rowSize,colSize;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int row,int col,vector<vector<int>>& grid,int &size){
        if(min(row,col)<0 || row>=rowSize || col>=colSize || grid[row][col]!=1) return;
        grid[row][col]=2;
        size++;
        for(auto&direction:directions)
            dfs(row+direction[0],col+direction[1],grid,size);
    }   
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        int area = 0;
        for(int row=0;row<rowSize;row++)
            for(int col=0;col<colSize;col++)
                if(grid[row][col]==1){
                    int size = 0;
                    dfs(row,col,grid,size);
                    area=max(area,size);
                }
        return area;
    }
};