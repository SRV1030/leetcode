class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int r=size(mat),c=size(mat[0]),l=0,h=r*c-1;
        while(l<=h){
            int m = (l+h)/2, x=m/c,y=m%c;
            if(mat[x][y]==t) return true;
            else if(mat[x][y]>t)h=m-1;
            else l=m+1;
        }
        return false;
    }
};