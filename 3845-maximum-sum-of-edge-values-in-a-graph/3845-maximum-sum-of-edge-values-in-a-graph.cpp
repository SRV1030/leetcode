class Solution {
public:
    vector<vector<int> > graph;
    vector<int> visitedNode;

    bool isConnectedComponent(vector<int> component){
        for(auto& node: component){
            if(graph[node].size() != 2)
                return false;
        }
        return true;
    }

    void fillAllNodesOfComponent(int node,vector<int>& component){
        visitedNode[node] = 1;
        component.push_back(node);
        for(auto& neighbour: graph[node])
            if(!visitedNode[neighbour])
                fillAllNodesOfComponent(neighbour, component);
    }

    long long calcualteScore(int startNodeValue, int endNodeValue, bool isCyclic){
        deque<long long> scoreSimulator = {endNodeValue, endNodeValue};
        long long totalScore = 0;
        for(long long currentNodeValue = endNodeValue - 1; currentNodeValue >= startNodeValue; currentNodeValue--){
            long long neighbourValue = scoreSimulator.front();
            scoreSimulator.pop_front();
            totalScore += neighbourValue * currentNodeValue;
            scoreSimulator.push_back(currentNodeValue);
        }
        if(isCyclic)
            totalScore += scoreSimulator[0] * scoreSimulator[1];
        return totalScore;
    }

    long long maxScore(int numberOfNodes, vector<vector<int>>& edges) {
        graph.resize(numberOfNodes);
        visitedNode.resize(numberOfNodes);

        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> cycles, paths;

        for(int node = 0; node < numberOfNodes; node++){
            if(!visitedNode[node]){
                vector<int> component;
                fillAllNodesOfComponent(node, component);
                if(isConnectedComponent(component))
                    cycles.push_back(component.size());
                else
                    paths.push_back(component.size());
            }
        }

        long long totalScore = 0, nodeValue = numberOfNodes;
        for(auto& cycle: cycles){
            totalScore += calcualteScore(nodeValue - cycle + 1, nodeValue, true);
            nodeValue -= cycle;
        }

        sort(paths.begin(), paths.end(), greater<int>());

        for(auto& path: paths){
            totalScore += calcualteScore(nodeValue - path + 1, nodeValue, false);
            nodeValue -= path;
        }

        return totalScore;
    }
};