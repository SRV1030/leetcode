class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& g){
        if(min(i,j)<0 || i>=g.size() || j>=g[0].size() || !g[i][j]) return 0;
        int cur=g[i][j];
        g[i][j]=0;
        cur+=dfs(i+1,j,g)+dfs(i,j+1,g)+dfs(i-1,j,g)+dfs(i,j-1,g);
        return cur;
    }
    int findMaxFish(vector<vector<int>>& g) {
        int mx=0;
        for(int i=0;i<g.size();i++)
            for(int j=0;j<g[0].size();j++)
                if(g[i][j])mx=max(mx,dfs(i,j,g));
        return mx;
    }
};