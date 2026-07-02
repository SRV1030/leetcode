class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for (auto &flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // minHeap -> {cost, node, edgesUsed}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, src, 0});

        // dist[node][edgesUsed]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int edges = curr[2];

            if (node == dst)
                return cost;

            if (edges == k + 1)
                continue;

            for (auto &[next, price] : graph[node]) {

                int newCost = cost + price;

                if (newCost < dist[next][edges + 1]) {

                    dist[next][edges + 1] = newCost;

                    pq.push({newCost, next, edges + 1});
                }
            }
        }

        return -1;
    }
};