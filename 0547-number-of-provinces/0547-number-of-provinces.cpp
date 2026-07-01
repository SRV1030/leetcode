class Solution {
    class DSU{
        vector<int> parents, ranks;
        int numberOfNodes, numberOfGroups;
    public:
        DSU(int nodes){
            numberOfNodes = nodes;
            numberOfGroups = nodes;
            parents = vector<int> (numberOfNodes);
            ranks = vector<int> (numberOfNodes, 1);
            iota(parents.begin(), parents.end(), 0);
        }

        int getParent(int node){
            if(node != parents[node])
                return parents[node] = getParent(parents[node]);
            return node;
        }

        void unite(int node1, int node2){
            int parent1 = getParent(node1), parent2 = getParent(node2);
            if(parent1 == parent2)
                return;
            if(ranks[parent1] < ranks[parent2]){
                parents[parent1] = parent2;
                ranks[parent2] += ranks[parent1];
            }
            else{
                parents[parent2] = parent1;
                ranks[parent1] += ranks[parent2];
            }
            --numberOfGroups;
        }

        int getGroups(){
            return numberOfGroups;
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());
        for(int row = 0; row < isConnected.size(); ++row){
            for(int col = 0; col < isConnected.size(); ++col){
                if(isConnected[row][col])   
                    dsu.unite(row, col);
            }
        }
        return dsu.getGroups();
    }
};