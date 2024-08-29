class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& g,vector<vector<int>>& g2,int i,int j,bool &check){
        if(min(i,j)<0 || i>=m || j>=n || !g[i][j]) return;
        if(g[i][j]!=g2[i][j])check=true;
        g[i][j] = 0;
        dfs(g,g2,i+1,j,check);
        dfs(g,g2,i-1,j,check);
        dfs(g,g2,i,j+1,check);
        dfs(g,g2,i,j-1,check);
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        m=g1.size(),n=g1[0].size();
        int c=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(g2[i][j]){
                    bool check =false;
                    dfs(g2,g1,i,j,check);
                    if(!check)++c;
                }
        return c;
    }
};