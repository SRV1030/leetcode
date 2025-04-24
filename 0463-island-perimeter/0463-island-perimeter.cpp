class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rowSize = grid.size(), colSize = grid[0].size(), perimeter = 0;
        for (int row = 0; row < rowSize; row++){
            for (int col = 0; col < colSize; col++){
                if (grid[row][col] == 1){
                    perimeter += 4;
                    if(row>0 && grid[row-1][col] == 1)
                        perimeter -= 2;
                    if(col>0 && grid[row][col-1] == 1)
                        perimeter-=2;
                }
            }
        }
        return perimeter;
    }
};