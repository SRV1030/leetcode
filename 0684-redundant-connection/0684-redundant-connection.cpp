class Solution {
public:
    vector<int>bw;
    bool dfs(vector<vector<int>> &g,vector<int>&vis,int src,int tg,int pr){
        // cout<<src<<" "<<tg<<"\n";
        if(src==tg) return true;
        vis[src]=1;
        for(auto&j:g[src]){
            if(src==pr && j==tg) continue;
            if(!vis[j]){
                if(dfs(g,vis,j,tg,src)) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& ed) {
        int n=ed.size();
        vector<vector<int>>gr(n+1);
        for(auto&i:ed){
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        for(int e=n-1;e>=0;e--){
            vector<int>vis(n+1);
            if(dfs(gr,vis,ed[e][0],ed[e][1],ed[e][0])) return ed[e];
        }
        return {};
    }
};