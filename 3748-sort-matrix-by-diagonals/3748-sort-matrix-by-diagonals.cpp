class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> indexMap;
        int rowSize = grid.size(), colSize = grid[0].size();
        vector<vector<int>> result(rowSize, vector<int> (colSize));
        for(int row = 0; row < rowSize; ++row)
            for(int col = 0; col < colSize; ++col)
                indexMap[row - col].push_back(grid[row][col]);
        for(auto&[key , array] : indexMap){
            if(key >= 0)
                sort(array.begin(), array.end(), greater<int>());
            else
                sort(array.begin(), array.end());
        }
        for(int row = 0; row < rowSize; ++row)
            for(int col = 0; col < colSize; ++col){
                result[row][col] = indexMap[row - col][0];
                indexMap[row - col].erase(indexMap[row - col].begin());
            }
        return result;
    }
};