class Solution {
public:
    void dijkstra(int source,
                  vector<vector<pair<int, long long>>>& graph,
                  vector<long long>& dist) {
        
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (wt != dist[node])
                continue;

            for (auto &[nb, edgeWt] : graph[node]) {
                if (dist[nb] > wt + edgeWt) {
                    dist[nb] = wt + edgeWt;
                    pq.push({dist[nb], nb});
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>>& edges,
                            int src1, int src2, int dest) {
        
        const long long INF = 1e18;

        vector<vector<pair<int, long long>>> g(n), revG(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            long long w = e[2];

            g[u].push_back({v, w});
            revG[v].push_back({u, w});
        }

        vector<long long> dist1(n, INF);
        vector<long long> dist2(n, INF);
        vector<long long> distDest(n, INF);

        dijkstra(src1, g, dist1);
        dijkstra(src2, g, dist2);
        dijkstra(dest, revG, distDest);

        long long ans = INF;

        for (int i = 0; i < n; i++) {
            if (dist1[i] == INF ||
                dist2[i] == INF ||
                distDest[i] == INF)
                continue;

            ans = min(ans,
                      dist1[i] + dist2[i] + distDest[i]);
        }

        return ans == INF ? -1 : ans;
    }
};