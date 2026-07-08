class Solution {
    class DSU{
        vector<int> parents, ranks;
        int nodes;
        public:
        DSU(int _n){
            nodes = _n;
            parents = vector<int>(nodes);
            ranks = vector<int>(nodes, 1);
            iota(parents.begin(), parents.end(), 0);
        }

        int find(int node){
            if(node == parents[node])
                return node;
            return parents[node] = find(parents[node]);
        }

        void join(int node1, int node2){
            int p1 = find(node1), p2 = find(node2);
            if(p1 == p2)
                return;
            if(ranks[p1] < ranks[p2]){
                parents[p1] = p2;
                ranks[p2] += ranks[p1];
            }
            else{
                parents[p2] = p1;
                ranks[p1] += ranks[p2];
            }
        }
        bool sameGroup(int node1, int node2){
            return find(node1) == find(node2);
        }
    };
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int size = source.size();
        DSU uf(size + 1);
        for(auto& swap : allowedSwaps)
            uf.join(swap[0], swap[1]);
        
        int dist = 0;
        unordered_map<int, vector<int>> groups; 
        for(int index = 0; index < size; ++index){
            groups[uf.find(index)].push_back(index);
        }
        for(auto& [_ , values] : groups){
            unordered_map<int, int> fr;
            for(auto& value : values){
                fr[source[value]]++;
                fr[target[value]]--;
            }
            for(auto&[key, value] : fr)
                if(value < 0)
                    dist += abs(value);
        }
        return dist; 
    }
};