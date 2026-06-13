class Solution {
    vector<int> parents, depths, result;
    const int MOD = 1e9 + 7;
    const int log = 18;
    const int MAXBASE = 100001;
    int size;
    vector<vector<int>> ancestors;
    vector<vector<int>> graph;
    vector<int> powerOf2;
public:
    void dfsWithAncesstor(int node, int parent, int depth){
        depths[node] = depth;
        ancestors[node][0] = parent;

        for(int bit = 1; bit < log; ++bit){
             ancestors[node][bit] =  ancestors[ancestors[node][bit - 1]][bit - 1];
        }

        for(auto& child : graph[node]){
            if(child == parent)
                continue;
            dfsWithAncesstor(child, node, depth + 1);
        }
    }


    int lca(int node1, int node2){
        if(depths[node1] < depths[node2]){
            swap(node1, node2);
        }

        int diff = depths[node1] - depths[node2];
        for(int bit = 0; diff > 0; ++bit){
            if(diff & 1)
                node1 = ancestors[node1][bit];
            diff >>= 1;
        }

        if(node1 == node2)
            return node1;
        
        for(int bit = log - 1; bit >= 0; --bit){
            if(ancestors[node1][bit] != ancestors[node2][bit]){
                node1 = ancestors[node1][bit];
                node2 = ancestors[node2][bit];
            }
        }


        return ancestors[node1][0];
    }

    int getPathLength(int node1, int node2){
        return depths[node1] + depths[node2] - 2 * depths[lca(node1, node2)];
    }

    void fillprevPowOf2(){
        long long cur = 1;
        for(int i = 1; i < MAXBASE; i++) {
            powerOf2[i] = cur;
            cur = (cur * 2) % MOD;
        }
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        size = edges.size() + 2;
        graph.resize(size);
        parents.resize(size);
        depths.resize(size);
        ancestors.assign(size + 1, vector<int> (log));
        powerOf2.resize(MAXBASE);
        fillprevPowOf2();
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfsWithAncesstor(1, 1, 0);
        for(auto& query : queries){
            result.push_back(powerOf2[getPathLength(query[0], query[1])]);
        }
        return result;
    }
}; 