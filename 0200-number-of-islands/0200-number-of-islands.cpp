class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int rowCount,columnCount;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(min(i,j)<0 || i>=rowCount || j>=columnCount || grid[i][j]!='1') return;
        grid[i][j] = '0';
        for(auto&d:dir)
            dfs(grid,d[0]+i,d[1]+j);
    }
    int numIslands(vector<vector<char>>& grid) {
        rowCount = grid.size();
        columnCount = grid[0].size();
        int islands = 0;
        for(int i=0;i<rowCount;i++)
            for(int j=0;j<columnCount;j++)
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ++islands;
                }
        return islands;
    }
};