class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allMask = (1 << n) - 1;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        queue<pair<int, int>> q;
        for (int node = 0; node < n; ++node) {
            int mask = 1 << node;
            q.push({node, mask});
            visited[node][mask] = true;
        }

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == allMask)
                    return dist;

                for (int nb : graph[node]) {
                    int newMask = mask | (1 << nb);

                    if (!visited[nb][newMask]) {
                        visited[nb][newMask] = true;
                        q.push({nb, newMask});
                    }
                }
            }

            ++dist;
        }

        return -1;
    }
};