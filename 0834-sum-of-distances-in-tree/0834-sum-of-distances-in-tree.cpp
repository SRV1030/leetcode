class Solution {
    vector<int> res, numberOfNodes;
    vector<vector<int>> graph; 
    int size;
public:
    void dfs(int node, int pr){
        for(auto& child : graph[node]){
            if(child == pr)
                continue;
            dfs(child, node);
            res[node] += res[child] + numberOfNodes[child];
            numberOfNodes[node] += numberOfNodes[child];
        }
        numberOfNodes[node]++;
    }
    void dfsReRoot(int node, int pr){
        for(auto& child : graph[node]){
            if(child == pr)
                continue;
            res[child] = res[node] - numberOfNodes[child] + size - numberOfNodes[child];
            dfsReRoot(child, node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n);
        numberOfNodes.resize(n);
        graph.resize(n);
        size = n;
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        dfsReRoot(0, -1);
        return res;
    }
};