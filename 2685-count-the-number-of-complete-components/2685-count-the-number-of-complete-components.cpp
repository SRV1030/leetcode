class Solution {
public:
    class DSU {
        int V;
        vector<int> parent, height;
        unordered_map<int, int> nodeToEdges;

    public:
        DSU(int n) {
            V = n;
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            height.resize(n, 1);
        }

        int find(int x) {
            if (parent[x] != x)
                return parent[x] = find(parent[x]);
            return x;
        }

        void unite(int u, int v) {
            int s1 = find(u), s2 = find(v);
            if (s1 == s2) {
                return;
            }
            if (height[s1] < height[s2]) {
                parent[s1] = s2;
                height[s2] += height[s1];
            } else {
                parent[s2] = s1;
                height[s1] += height[s2];
            }
        }

        void fillNodeEdgesCount(vector<vector<int>>& edges) {
            for (auto& e : edges)
                nodeToEdges[find(e[0])]++;
        }

        int getComponents() {
            int components = 0;
            for (int i = 0; i < V; i++)
                if (parent[i] == i) {
                    int nodes = height[i];
                    int edgeCount = (nodes * (nodes - 1)) / 2;
                    if (edgeCount == nodeToEdges[i])
                        ++components;
                }
            return components;
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU uf(n);
        for (auto& e : edges)
            uf.unite(e[0], e[1]);
        uf.fillNodeEdgesCount(edges);
        return uf.getComponents();
    }
};