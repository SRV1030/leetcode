class Solution {
public:
    vector<vector<int>>gr;
    void dfs(int i,int j,int m,int n,char c){
        if(min(i,j)<0 || i>=m || j>=n || gr[i][j]==1 || gr[i][j]==2) return;
        gr[i][j]=3;
        if(c=='U')dfs(i+1,j,m,n,'U');
        if(c=='D')dfs(i-1,j,m,n,'D');
        if(c=='L')dfs(i,j+1,m,n,'L');
        if(c=='R')dfs(i,j-1,m,n,'R');
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        gr=vector<vector<int>>(m,vector<int>(n));
        for(auto&i:guards)gr[i[0]][i[1]]=1;
        for(auto&i:walls)gr[i[0]][i[1]]=2;
        for(auto&x:guards){
            int i=x[0],j=x[1];
            dfs(i+1,j,m,n,'U');
            dfs(i-1,j,m,n,'D');
            dfs(i,j+1,m,n,'L');
            dfs(i,j-1,m,n,'R');
        }
        int c=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)c+=gr[i][j]==0;
        return c;
    }
};