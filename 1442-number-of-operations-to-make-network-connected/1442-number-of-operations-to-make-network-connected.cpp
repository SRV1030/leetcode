class Solution {
public:
    vector<int> group, rank;
    int getGroup(int component) {
        while (component != group[component])
            return group[component] = getGroup(group[component]);
        return component;
    }
    void connect(int u, int v) {
        int g1 = getGroup(u), g2 = getGroup(v);
        if (g1 != g2) {
            if (rank[g1] < rank[g2]) {
                group[g1] = g2;
                rank[g2] += rank[g1];
            } else {
                group[g2] = g1;
                rank[g1] += rank[g2];
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        group.resize(n);
        rank.resize(n);
        iota(group.begin(), group.end(), 0);
        for (auto& component : connections)
            connect(component[0], component[1]);
        int disconnectedComponents = 0;
        for (int i = 0; i < n; i++)
            if (group[i] == i)
                ++disconnectedComponents;
        return disconnectedComponents - 1;
    }
};