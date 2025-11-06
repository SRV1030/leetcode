class Solution {
    class DSU{
        int nodes;
        vector<int> parents, ranks;
        unordered_map<int, set<int>> connections;
        vector<int> alive;
    public:
        DSU(int _nodes){
            nodes = _nodes;
            parents = vector<int>(nodes + 1);
            ranks = vector<int>(nodes + 1, 1);
            iota(parents.begin(), parents.end(), 0);
            alive = vector<int>(nodes + 1, 1);
        }

        int find(int node){
            if(node != parents[node])
                return parents[node] = find(parents[node]);
            return node;
        }

        void unite(int child1, int child2){
            int p1 = find(child1), p2 = find(child2);
            if(p1 == p2)
                return;
            if(ranks[p1] < ranks[p2]){
                ranks[p2] += ranks[p1];
                parents[p1] = p2;
            }
            else{
                ranks[p1] += ranks[p2];
                parents[p2] = p1;
            }
        }

        void formGrid(){
            for(int node = 1; node <= nodes; ++node)
                connections[find(node)].insert(node);
        }

        void unsetGrid(int node){
            if(alive[node]){
                alive[node] = 0;
                int key = find(node);
                connections[key].erase(node);
                if(connections[key].empty())
                    connections.erase(key);
            }
        }

        int getStation(int node){
            if(alive[node])
                return node;
            int key = find(node);
            if(connections.count(key))
                return *(connections[key].begin());
            return -1;
        }
    };
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU uf(c);
        for(auto& connection : connections)
            uf.unite(connection[0], connection[1]);
        vector<int> result;
        uf.formGrid();
        for(auto& query : queries){
            if(query[0] == 1)
                result.push_back(uf.getStation(query[1]));
            else
                uf.unsetGrid(query[1]);
        }
        return result;
    }
};