class Solution {
public:
    int rowSize,colSize,maxFinal = 0;
    vector<vector<int>> directions = {{0,1},{1,0},{1,1}};
    vector<vector<int>> dp;
    int findMax(int row,int col,vector<vector<char>>& matrix){
        if(row>=rowSize || col>=colSize || matrix[row][col]!='1') return 0;

        if(dp[row][col]!=-1) return dp[row][col];
        
        int maxLength = INT_MAX;

        for(auto direction : directions){
            maxLength = min(maxLength,findMax(row+direction[0],col+direction[1],matrix));
        }
        maxLength+=1;
        // cout<<row<<" "<<col<<" "<<maxLength<<"\n";
        maxFinal = max(maxFinal,maxLength);
        return dp[row][col] = maxLength;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        rowSize = matrix.size();
        colSize = matrix[0].size();
        dp.resize(rowSize+1,vector<int>(colSize+1,-1));
        for(int row = 0;row<rowSize;row++)
            for(int col=0;col<colSize;col++)
                if(matrix[row][col]=='1')
                    maxFinal = max(maxFinal,findMax(row,col,matrix));
        return maxFinal * maxFinal;
    }
};