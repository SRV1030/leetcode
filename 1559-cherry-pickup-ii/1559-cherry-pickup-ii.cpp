class Solution {
public:
    int rowSize,colSize;
    int memory[71][71][71];
    int pickMaxCherries(int row1,int col1,int col2,vector<vector<int>>& grid){
        if(min({row1,col1,col2})<0 || row1>=rowSize || max(col1,col2)>=colSize) return INT_MIN;
        int &cherries = memory[row1][col1][col2];
        if(cherries!=-1) return cherries;
        cherries = col1==col2?grid[row1][col1]:grid[row1][col1]+grid[row1][col2];
        if(row1==rowSize) return cherries;
        int nextMaxPick = 0;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++){
                nextMaxPick = max(nextMaxPick,pickMaxCherries(row1+1,col1+i,col2+j,grid));
            }
        cherries+=nextMaxPick;
        return cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        memset(memory,-1,sizeof(memory));
        return pickMaxCherries(0,0,colSize-1,grid);
    }
};