class Solution {
    unordered_map<int, unordered_map<int, int>> graph;
    vector<int> result;
public:
    int countReversal(int parent, int node){
        int reversals = 0;
        for(auto& [child, weight] : graph[node]){
            if(child == parent)
                continue;
            reversals += weight + countReversal(node, child);
        }
        return reversals;
    }
    void propagateReversals(int parent, int node, int reversals){
        result[node] = reversals;
        for(auto& [child, weight] : graph[node]){
            if(child == parent)
                continue;
            propagateReversals(node, child, reversals - weight + graph[child][node]);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        for(auto& edge : edges){
            graph[edge[0]][edge[1]] = 0, graph[edge[1]][edge[0]] = 1;
        }
        int node0Reversals = countReversal(-1, 0);
        result = vector<int>(n, -1);
        propagateReversals(-1, 0, node0Reversals);
        return result;
    }
};