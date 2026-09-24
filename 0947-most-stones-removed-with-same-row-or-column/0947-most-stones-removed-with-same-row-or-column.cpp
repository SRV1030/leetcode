class Solution {
public:
    class UnionFind {
        vector<int> parents, ranks;
        int numberOfNodes, numberOfParents;

    public:
        UnionFind(int _numberOfNodes) {
            numberOfNodes = _numberOfNodes;
            numberOfParents = _numberOfNodes;

            parents = vector<int>(_numberOfNodes);
            ranks = vector<int>(_numberOfNodes, 1);

            iota(parents.begin(), parents.end(), 0);
        }

        int findParent(int node) {
            if (node != parents[node])
                return parents[node] = findParent(parents[node]);

            return node;
        }

        void unite(int node1, int node2) {
            int parent1 = findParent(node1);
            int parent2 = findParent(node2);

            if (parent1 == parent2)
                return;

            if (ranks[parent1] < ranks[parent2]) {
                parents[parent1] = parent2;
                ranks[parent2] += ranks[parent1];
            }
            else {
                parents[parent2] = parent1;
                ranks[parent1] += ranks[parent2];
            }

            --numberOfParents;
        }

        int numberOfChildren() {
            return numberOfNodes - numberOfParents;
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        UnionFind unionFind(n);

        unordered_map<int, int> row;
        unordered_map<int, int> col;

        for (int i = 0; i < n; i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            // Same row
            if (row.count(r))
                unionFind.unite(i, row[r]);
            else
                row[r] = i;

            // Same column
            if (col.count(c))
                unionFind.unite(i, col[c]);
            else
                col[c] = i;
        }

        return unionFind.numberOfChildren();
    }
};