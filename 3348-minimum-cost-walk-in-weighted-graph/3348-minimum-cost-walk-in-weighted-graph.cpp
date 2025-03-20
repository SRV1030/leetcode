class Solution {
public:
    class DSU {
        vector<int>mnW;
        vector<int> parent, height;

    public:
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            height.resize(n, 1);
            mnW.resize(n,-1);
        }
        void addCost(int root,int w){
            mnW[root]&=w;
        }
        int getmnW(int x) { return mnW[x]; }
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
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        DSU uf(n + 1);

        for (auto& e : edges)
            uf.unite(e[0], e[1]);

        for (auto& e : edges)
            uf.addCost(uf.find(e[0]), e[2]);

        vector<int> ans;

        for (auto& q : query) {
            int s1 = uf.find(q[0]), s2 = uf.find(q[1]);
            cout<<s1<<" "<<s2<<"\n";
            if (s1 == s2)
                ans.push_back(uf.getmnW(s1));
            else
                ans.push_back(-1);
        }
        return ans;
    }
};