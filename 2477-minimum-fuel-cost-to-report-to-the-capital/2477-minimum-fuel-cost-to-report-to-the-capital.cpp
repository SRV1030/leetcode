class Solution {
    long long ans = 0, seats, size;
    vector<vector<int>> graph;
public:
    long long dfs(int node, int parent){
        long long people = 1;
        for(auto& child : graph[node]){
            if(child == parent)
                continue;
            people += dfs(child, node);
        }
        if(node != 0)
            ans += (people + seats - 1) / seats;
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int& _seats) {
        seats = _seats;
        size = roads.size();
        graph = vector<vector<int>>(size + 1);
        for(auto& road : roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        dfs(0, 0);
        return ans;
    }
};