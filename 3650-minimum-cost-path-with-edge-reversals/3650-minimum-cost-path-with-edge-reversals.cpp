class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto&edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], 2 * edge[2]});
        }
        vector<int> dist(n, 1e9);
        vector<int> visited(n);
        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({0, 0});
        dist[0] = 0;
        while(!maxHeap.empty()){
            int node = maxHeap.top().second;
            maxHeap.pop();
            if(visited[node])
                continue;
            visited[node] = 1;
            for(auto& [nb, w] : graph[node]){
                if(dist[node] + w < dist[nb]){
                    dist[nb] = dist[node] + w;
                    maxHeap.push({-dist[nb], nb});
                }
            }
        }        
        return dist[n - 1] == 1e9 ? -1 : dist[n - 1];
    }
};