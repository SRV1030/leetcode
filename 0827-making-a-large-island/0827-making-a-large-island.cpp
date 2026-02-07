class Solution {
    class DSU {
        vector<int> parent, rank;

    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int getRank(int node){
            return rank[node];
        }

        int find(int child) {
            if (child != parent[child])
                parent[child] = find(parent[child]);
            return parent[child];
        }

        void unite(int index1, int index2) {
            int parent1 = find(index1), parent2 = find(index2);
            if (parent1 == parent2)
                return;
            if (rank[parent1] < rank[parent2]) {
                parent[parent1] = parent2;
                rank[parent2] += rank[parent1];
            } else {
                parent[parent2] = parent1;
                rank[parent1] += rank[parent2];
            }
        }

        bool isSameSet(int index1, int index2) {
            return find(index1) == find(index2);
        }
    };
public:
    int index(int &row, int &col, int &colSize){
        return row * colSize + col;
    }

    bool outOfBound(int &row, int &col, int &size){
        return min(row, col) < 0 || max(row, col) >= size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int size = grid.size(), maxArea = 0;
        DSU uf(size * size);
        unordered_map<int, int> areas;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int row = 0; row < size; ++row){
            for(int col = 0; col < size; ++col){
                if(grid[row][col]){
                    int parentIndex = index(row, col, size);
                    for(auto& dir : directions){
                        int x = row + dir[0], y = col + dir[1];
                        if(!outOfBound(x, y, size) && grid[x][y])
                            uf.unite(parentIndex, index(x, y, size));
                    }
                    maxArea = max(maxArea, uf.getRank(uf.find(parentIndex)));
                }
            }
        }

        for(int row = 0; row < size; ++row){
            for(int col = 0; col < size; ++col){
                if(!grid[row][col]){
                    unordered_set<int> islands;
                    int area = 1;
                    for(auto& dir : directions){
                        int x = row + dir[0], y = col + dir[1];
                        if(!outOfBound(x, y, size) && grid[x][y]){
                            int islandIndex = uf.find(index(x, y, size));
                            if(islands.insert(islandIndex).second){
                                area += uf.getRank(islandIndex);
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};