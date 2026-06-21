class Solution {
public:
    long long shortestPath(int n, vector<vector<int>>& edges,
                           string labels, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto &e : edges)
            graph[e[0]].push_back({e[1], e[2]});

        const long long INF = 1e18;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if(d != dist[u][cnt])
                continue;

            for(auto &[v, w] : graph[u]) {

                int nextCnt;

                if(labels[u] == labels[v])
                    nextCnt = cnt + 1;
                else
                    nextCnt = 1;

                if(nextCnt > k)
                    continue;

                long long nd = d + w;

                if(nd < dist[v][nextCnt]) {
                    dist[v][nextCnt] = nd;
                    pq.push({nd, v, nextCnt});
                }
            }
        }

        long long ans = INF;

        for(int cnt = 1; cnt <= k; cnt++)
            ans = min(ans, dist[n - 1][cnt]);

        return ans == INF ? -1 : ans;
    }
};