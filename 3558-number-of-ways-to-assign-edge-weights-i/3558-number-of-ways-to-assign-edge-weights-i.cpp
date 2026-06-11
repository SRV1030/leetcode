class Solution {
    const int MOD = 1e9 + 7;
public:
    int power(long long a, long long b){
        long long res = 1;
        while(b){
            if(b % 2)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return (int)res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int maxDepth = 0, nodes = edges.size() + 2;
        vector<vector<int>> graph(nodes);
        vector<int> visited(nodes);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({1 , 0});
        visited[1] = 1;
        while(!bfsQueue.empty()){
            auto [node, depth] = bfsQueue.front();
            bfsQueue.pop();
            maxDepth = max(maxDepth, depth);
            for(auto& child : graph[node]){
                if(!visited[child]){
                    visited[child] = 1;
                    bfsQueue.push({child, depth + 1});
                }
            }
            
        }
        return power(2, maxDepth - 1);
    }
};