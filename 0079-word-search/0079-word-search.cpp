class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    bool findWord(vector<vector<char>>& grid, string &word,int i,int j,int ind){
        if(ind>=word.size()) return true;
        if(min(i,j)<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=word[ind]) return false;
        char ch = grid[i][j];
        grid[i][j] = '$';
        bool check = false;
        for(auto&d:dir) check|=findWord(grid,word,i+d[0],j+d[1],ind+1);
        grid[i][j] = ch;
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(findWord(board,word,i,j,0)) return true;
        return false;
    }
};