class Solution {
    vector<vector<int>> graph;
    int components = 0;
public:
    int dfs(vector<int>& values, int& k, int node, int parent){
        int sum = 0;
        for(auto& child : graph[node]){
            if(child != parent){
                sum += dfs(values, k, child, node);
                sum %= k;
            }
        }
        sum += values[node];
        sum %= k;
        if(sum == 0)
            ++components;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        graph = vector<vector<int>> (n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(values, k, 0, -1);
        return components;
    }
};