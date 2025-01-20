class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();
        vector<int>rc(r,c),cc(c,r);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)mp[mat[i][j]]={i,j};
        for(int i=0;i<size(arr);i++){
            auto it=mp[arr[i]];
            rc[it[0]]--;
            cc[it[1]]--;
            if(!rc[it[0]] || !cc[it[1]]) return i;
        }
        return -1;
    }
};