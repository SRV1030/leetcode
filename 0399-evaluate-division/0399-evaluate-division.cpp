class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
    int size;
public:
    double calculateDivision(string numerator, string denominator, unordered_set<string>& visited){
        if(numerator == denominator)
            return 1;
        for(auto& [nextNumerator, ratio]: graph[numerator]){
            if(visited.insert(nextNumerator).second){
                double division = calculateDivision(nextNumerator, denominator, visited);
                if(division != -1)
                    return division * ratio;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        size = equations.size();
        for(int index = 0; index < size; ++index){
            graph[equations[index][0]].push_back({equations[index][1], values[index]});
            graph[equations[index][1]].push_back({equations[index][0], 1.0 / values[index]});
        }
        vector<double> queryResults;
        for(auto& query: queries){
            if(!graph.count(query[0]) || !graph.count(query[1])){
                queryResults.push_back(-1);
            }
            else{
                unordered_set<string> visited;
                queryResults.push_back(calculateDivision(query[0], query[1], visited));
            }
        }
        return queryResults;
    }
};