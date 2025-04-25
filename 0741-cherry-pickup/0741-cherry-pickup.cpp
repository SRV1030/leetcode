class Solution {
public:
    int rowSize, colSize;
    int dp[50][50][50];
    bool isValidIndex(int row1,int row2,int col1,int col2){
        return min({row1,row2,col1,col2})<0 || max(row1,row2)>=rowSize || max(col1,col2)>=colSize;
    }
    int maxCherries(int row1,int col1,int col2,vector<vector<int>>& grid){
        int row2 = row1+col1-col2;
        if ( isValidIndex(row1,row2,col1,col2) || grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return INT_MIN;
        if(row1 == rowSize-1 && col1==colSize-1) return grid[row1][col1];
        int &cherries = dp[row1][col1][col2];
        if(cherries!=-1) return cherries;
        cherries = (col1==col2)?grid[row1][col1]:grid[row1][col1]+grid[row2][col2];
        int maxNextPick = max({maxCherries(row1+1,col1,col2,grid),maxCherries(row1,col1+1,col2+1,grid),
                            maxCherries(row1+1,col1,col2+1,grid),maxCherries(row1,col1+1,col2,grid)});
        cherries+=maxNextPick;
        return cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return max(0,maxCherries(0,0,0,grid));
    }
};