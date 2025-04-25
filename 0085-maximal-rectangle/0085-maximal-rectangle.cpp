class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> height(colSize),leftLength(colSize),rightLength(colSize,colSize);
        int maxArea = 0;
        for(int row = 0;row < rowSize; row++){
            int left = 0,right = colSize;
            for(int col = 0; col < colSize; col++){
                if(matrix[row][col]=='1') leftLength[col] = max(leftLength[col],left);
                else {
                    leftLength[col] = 0;
                    left = col + 1;
                }
            }

            for(int col = 0; col < colSize; col++){
                if(matrix[row][col]=='1') height[col]++;
                else height[col] = 0;
            }

            for(int col = colSize - 1; col >=0; col--){
                if(matrix[row][col]=='1') {
                    rightLength[col] = min(right,rightLength[col]);
                }
                else {
                    rightLength[col] = colSize;
                    right = col;
                }
            }

            for(int col = 0; col < colSize; col++)
                maxArea = max(maxArea, (rightLength[col] - leftLength[col]) * height[col]);
            
        }
        return maxArea;
    }
};