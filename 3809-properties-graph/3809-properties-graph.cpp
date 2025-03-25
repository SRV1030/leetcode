class Solution {
public:
    bool isIntersected(vector<int> property_1, vector<int> property_2, int k) {
        bitset<101> mask_1, mask_2;
        for (auto& i : property_1)
            mask_1.set(i);
        for (auto& i : property_2)
            mask_2.set(i);

        mask_1 &= mask_2;
        int common = 0;
        for (int i = 0; i < 101; i++)
            if (mask_1[i])
                ++common;
        return common >= k;
    }
    class DSU {
        vector<int> parent, height;
        int V;

    public:
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            height.resize(n, 1);
            V = n;
        }

        int find(int x) {
            if (x != parent[x])
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
        int getConnectedComponents() {
            int comp = 0;
            for (int i = 0; i < V; i++)
                if (i == parent[i])
                    ++comp;
            return comp;
        }
    };
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        DSU uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                if (isIntersected(properties[i], properties[j], k))
                    uf.unite(i, j);
        }
        return uf.getConnectedComponents();
    }
};