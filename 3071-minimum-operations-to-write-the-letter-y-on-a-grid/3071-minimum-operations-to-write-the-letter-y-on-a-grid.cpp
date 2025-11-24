class Solution {
    bool isOnY(int &size, int &row, int &col, int &center){
        return (row == col && row <= center) || ((row + col + 1) == size && row <= center) || (row > center && col == center);
    }
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int size = grid.size();
        int center = size / 2, ySize = 3 * center, rest = size * size - ySize;
        vector<int> yFrequency(3), nonYFrequency(3);
        int minOps = INT_MAX;
        for(int row = 0; row < size; ++row){
            for(int col = 0; col < size; ++col){
                if(isOnY(size, row, col, center))
                    yFrequency[grid[row][col]]++;
                else
                    nonYFrequency[grid[row][col]]++;
            }
        }
        for(int y = 0; y < 3; ++y){
            for(int ny = 0; ny < 3; ++ny){
                if(y == ny)
                    continue;
                minOps = min(minOps, ySize - yFrequency[y] + rest - nonYFrequency[ny]);
            }
        }
        return minOps;
    }
};