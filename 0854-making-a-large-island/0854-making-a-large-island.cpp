class Solution {
public:
    class DSU {
        vector<int> parent, rank;

    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int findParent(int child) {
            if (child != parent[child])
                parent[child] = findParent(parent[child]);
            return parent[child];
        }

        void unite(int index1, int index2) {
            int parent1 = findParent(index1), parent2 = findParent(index2);
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
            return findParent(index1) == findParent(index2);
        }
    };

    int rowSize, colSize;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int index(int row, int col) { return row * colSize + col; }

    bool isInValidIndex(int row, int col) {
        return row < 0 || col < 0 || row >= rowSize || col >= colSize;
    }

    int largestIsland(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        DSU uf(rowSize * colSize);
        unordered_map<int, int> islandToArea;

        // Step 1: Union all 1s and record island area
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                if (grid[row][col] == 1) {
                    for (auto& dir : directions) {
                        int newRow = row + dir[0], newCol = col + dir[1];
                        if (!isInValidIndex(newRow, newCol) && grid[newRow][newCol] == 1)
                            uf.unite(index(row, col), index(newRow, newCol));
                    }
                }
            }
        }

        // Step 2: Count area for each unique island
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                if (grid[row][col] == 1) {
                    int parentIdx = uf.findParent(index(row, col));
                    islandToArea[parentIdx]++;
                }
            }
        }

        int maxArea = 0;
        for (auto& [_, area] : islandToArea) {
            maxArea = max(maxArea, area);
        }

        // Step 3: Try flipping 0s to 1 and calculate potential area
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                if (grid[row][col] == 0) {
                    unordered_set<int> uniqueIslands;
                    int area = 1;
                    for (auto& dir : directions) {
                        int newRow = row + dir[0], newCol = col + dir[1];
                        if (!isInValidIndex(newRow, newCol) && grid[newRow][newCol] == 1) {
                            int parentIdx = uf.findParent(index(newRow, newCol));
                            if (uniqueIslands.insert(parentIdx).second) {
                                area += islandToArea[parentIdx];
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
