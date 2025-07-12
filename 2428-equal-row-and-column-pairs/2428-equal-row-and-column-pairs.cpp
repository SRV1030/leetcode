class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size(), pairs = 0;
        map<vector<int>, int> coloumnFrequencyMap;
        for(int col = 0; col < size; ++col){
            vector<int> columnHash;
            for(int row = 0; row < size; ++row)
                columnHash.push_back(grid[row][col]);
            ++coloumnFrequencyMap[columnHash];
        }
        for(auto& rows: grid){
            pairs += coloumnFrequencyMap[rows];
        }
        return pairs;
    }
};