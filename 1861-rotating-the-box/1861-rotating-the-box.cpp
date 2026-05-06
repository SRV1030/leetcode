class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rows = boxGrid.size(), cols = boxGrid[0].size();
        vector<vector<char>> result(cols, vector<char>(rows, '.'));

        for(int row = 0; row < rows; ++row){
            int floor = cols - 1;
            for(int col = cols - 1; col >= 0; --col){
                if(boxGrid[row][col] == '#'){
                    result[floor][rows - row - 1] = '#';
                    --floor; 
                }
                else if(boxGrid[row][col] == '*'){
                    floor = col - 1;
                    result[col][rows - row - 1] = '*';
                }
            }
        }
        return result;
    }
};