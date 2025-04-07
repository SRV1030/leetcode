class Solution {
public:
    vector<int>vis;
    bool dfs(int i,int parent,vector<vector<int>>& graph,int color){
        vis[i] = color;
        bool ans = true;
        for(auto&nb:graph[i]){
            if(!vis[nb]) ans&=dfs(nb,i,graph,3-color);
            else if(nb!=parent && vis[nb]==vis[i]) return false; 
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int size= graph.size();
        vis.resize(size+1);
        for(int i=0;i<size;i++){
            if(!vis[i] && !dfs(i,size,graph,1)) return false;
        }
        return true;
    }
};