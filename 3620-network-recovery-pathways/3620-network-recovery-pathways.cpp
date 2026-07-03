class Solution {
public:
    bool dijkstra(vector<vector<pair<int, int>>>& graph, vector<bool>& online,
                  int minEdge, long long k) {

        int nodes = online.size();
        vector<long long> distance(nodes, LLONG_MAX);

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        distance[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost != distance[u])
                continue;

            if (cost > k)
                continue;

            if (u == nodes - 1)
                return true;

            for (auto &[v, wt] : graph[u]) {
                if (!online[v] || wt < minEdge)
                    continue;

                if (cost + wt < distance[v]) {
                    distance[v] = cost + wt;
                    pq.push({distance[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int rows = edges.size();
        if (!rows)
            return -1;

        int nodes = online.size();
        vector<vector<pair<int, int>>> graph(nodes);

        int low = INT_MAX, high = INT_MIN;

        for (auto &edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            low = min(low, edge[2]);
            high = max(high, edge[2]);
        }

        if (!online[0] || !online[nodes - 1])
            return -1;

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (dijkstra(graph, online, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};