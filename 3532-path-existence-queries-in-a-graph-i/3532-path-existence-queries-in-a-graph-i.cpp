class Solution {
    class DSU{
        vector<int> ranks, parents;
        int size;
    public:
        DSU(int _size){
            size = _size;
            ranks = vector<int>(size, 1);
            parents = vector<int>(size);
            iota(parents.begin(), parents.end(), 0);
        }

        int find(int node){
            return node == parents[node] ? node : (parents[node] = find(parents[node]));
        }

        void unite(int node1, int node2){
            int p1 = find(node1), p2 = find(node2);
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
    };
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> numToIndex;
        for(int node = 0; node < n; ++node){
            numToIndex.push_back({nums[node], node});
        }
        sort(numToIndex.begin(), numToIndex.end());
        DSU uf(n + 1);
        for(int ind = 1; ind < n; ++ind){
            if(numToIndex[ind][0] - numToIndex[ind - 1][0] <= maxDiff)
                uf.unite(numToIndex[ind - 1][1], numToIndex[ind][1]);
        }
        vector<bool> res;
        for(auto& query : queries)
            res.push_back(uf.find(query[0]) == uf.find(query[1]));
        return res;
    }
};