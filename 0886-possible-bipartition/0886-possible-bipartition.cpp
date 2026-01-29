class Solution {
    vector<vector<int>> graph;
    vector<int> colors;
public:
    bool dfs(int node, int color){
        colors[node] = color;
        bool ans = true;
        for(auto& child : graph[node]){
            if(!colors[child])
                ans &= dfs(child, 3 - color);
            else if(colors[child] == colors[node])
                return false;
        }
        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>> (n + 1);
        colors = vector<int>(n + 1);
        for(auto& dislike : dislikes){
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        for(int node = 1; node <= n; ++node){
            if(!colors[node] && !dfs(node, 1))
                return false;
        }
        return true;
    }
};