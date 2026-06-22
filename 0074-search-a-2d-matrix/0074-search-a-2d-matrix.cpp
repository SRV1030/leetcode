class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size(), low = 0, high = rows * cols - 1;
        while(low <= high){
            int mid = (low + high) / 2, midRow = mid / cols, midCol = mid % cols;
            if(matrix[midRow][midCol] == target)
                return true;
            if(matrix[midRow][midCol] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};