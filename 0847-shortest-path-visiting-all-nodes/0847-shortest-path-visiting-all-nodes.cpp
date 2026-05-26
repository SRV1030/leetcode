class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<vector<int>> bfsQueue;
        set<vector<int>> visited;
        int nodes = graph.size();
        int allPos = (1 << nodes) - 1;
        for(int node = 0; node < nodes; ++node){
            int mask = 1 << node;
            bfsQueue.push({node, 0, mask});
            visited.insert({node, mask});
        }
        while(!bfsQueue.empty()){
            vector<int> state = bfsQueue.front();
            bfsQueue.pop();
            if(state[2] == allPos)
                return state[1];
            for(auto& nb : graph[state[0]]){
                int mask = state[2] | (1 << nb);
                if(visited.insert({nb, mask}).second){
                    bfsQueue.push({nb, state[1] + 1, mask});
                }
            }
        }
        return -1;
    }
};