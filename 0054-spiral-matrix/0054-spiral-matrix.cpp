class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int row = matrix.size(), column = matrix[0].size(), i = 0, j = 0;
        while (i < row && j < column) {
            for (int k = j; k < column; k++)
                answer.push_back(matrix[i][k]);
            i++;
            for (int k = i; k < row; k++)
                answer.push_back(matrix[k][column - 1]);
            column--;
            if (i < row) {
                for (int k = column - 1; k >= j; k--)
                    answer.push_back(matrix[row - 1][k]);
                row--;
            }
            if (j < column) {
                for (int k = row - 1; k >= i; k--)
                    answer.push_back(matrix[k][j]);
                j++;
            }
        }
        return answer;
    }
};