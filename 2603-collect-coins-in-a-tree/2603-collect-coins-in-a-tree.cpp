class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int size = coins.size();
        vector<set<int>> graph(size);
        for(auto& edge: edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        queue<int> leaves;
        int totalEdges = edges.size() * 2, deleted = 0;
        for(int index = 0; index < size; ++index)
            if(graph[index].size() == 1 && coins[index] == 0)
                leaves.push(index);
        
        while(leaves.size()){
            int leaf = leaves.front();
            leaves.pop();
            if(graph[leaf].empty())
                continue;
            int parent = *graph[leaf].begin();
            graph[parent].erase(leaf);
            graph[leaf].erase(parent);
            deleted+=2;

            if(graph[parent].size() == 1 && coins[parent] == 0)
                leaves.push(parent);
        }

        for(int index = 0; index < size; ++index){
            if(graph[index].size() == 1)
                leaves.push(index);
        }
        int steps = 2;
        while(steps--){
            int loop = leaves.size();
            while(loop--){
                int leaf = leaves.front();
                leaves.pop();
                if(!graph[leaf].size())
                    continue;
                
                int parent = *graph[leaf].begin();
                graph[parent].erase(leaf);
                graph[leaf].erase(parent);
                deleted+=2;

                if(graph[parent].size() == 1)
                    leaves.push(parent);
            }
        }

        return totalEdges - deleted;
    }
};