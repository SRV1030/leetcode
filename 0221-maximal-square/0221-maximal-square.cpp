class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int maxLength = 0;
        vector<vector<int>> dp(rowSize+1,vector<int>(colSize+1,0));
        for(int i=1;i<=rowSize;i++)
            for(int j=1;j<=rowSize;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    maxLength = max(maxLength,dp[i][j]);
                }
            }
        return maxLength * maxLength;
    }
};