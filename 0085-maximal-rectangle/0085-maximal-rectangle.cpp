class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int area = 0, rows = matrix.size(), cols = matrix[0].size();
        vector<int> left(cols), right(cols, cols), height(cols);
        for(int row = 0; row < rows; ++row){
            int curLeft = 0, curRight = cols;
            for(int col = 0; col < cols; ++col){
                if(matrix[row][col] == '1'){
                    height[col]++;
                    left[col] = max(curLeft, left[col]);
                }
                else{
                    height[col] = 0;
                    left[col] = 0;
                    curLeft = col + 1;
                }
            }
            for(int col = cols - 1; col >= 0; --col){
                if(matrix[row][col] == '1'){
                    right[col] = min(curRight, right[col]);
                }
                else{
                    right[col] = cols;
                    curRight = col;
                }
            }
            for(int col = 0; col < cols; ++col){
                area = max(area,(right[col] - left[col]) * height[col]);
            }
        }
        return area;
    }
};