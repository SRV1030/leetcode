class Solution {
public:
    void dfs(vector<vector<int>> &g,int i,vector<int>&vis){
        vis[i]=1;
        for(auto& j:g[i]){
            if(!vis[j]){
                dfs(g,j,vis);
            }
        }
    } 
    int removeStones(vector<vector<int>>& stones) {
        int n=size(stones);
        vector<vector<int>> g(n);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int cn=0;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(g,i,vis);
                ++cn;
            }
        }
        return n-cn;
    }
};