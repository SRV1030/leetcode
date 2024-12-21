class Solution {
public:
    int dfs(vector<int> adj[],int cur,int prnt,vector<int>& values,int k,int& c){
        int sm=0;
        for(auto&i:adj[cur]){
            if(i!=prnt){
                sm+=dfs(adj,i,cur,values,k,c);
                sm%=k;
            }
        }
        sm+=values[cur];
        sm%=k;
        if(sm==0)++c;
        return sm;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int c=0;
        vector<int>adj[n];
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(adj,0,-1,values,k,c);
        return c;
    }
};