class Solution {
public:
    int getIJ(vector<vector<int>>& matrix,int i,int j){
        if(min(i,j)<0 || i>=matrix.size() || j>=matrix[0].size()) return INT_MAX;
        return matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                matrix[i][j]+=min({getIJ(matrix,i-1,j),getIJ(matrix,i-1,j-1),getIJ(matrix,i-1,j+1)});
            }
        }
        return *min_element(matrix[r-1].begin(),matrix[r-1].end());
    }
};