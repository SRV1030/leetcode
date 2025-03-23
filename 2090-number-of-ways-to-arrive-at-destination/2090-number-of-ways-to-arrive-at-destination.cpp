class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<vector<pair<int, int>>> gr(n);
        for(auto&e:roads){
            gr[e[0]].push_back({e[1],e[2]});
            gr[e[1]].push_back({e[0],e[2]});
        }
        vector<long long>shortestTime(n,LONG_MAX);
        shortestTime[0]=0;
        pq.push({0,0});
        vector<int>paths(n);
        paths[0]=1;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            long long curr_node = top.second, curr_time=top.first;
            for(auto&nb:gr[curr_node]){
                long long nb_node  = nb.first, nb_time=nb.second;
                if(curr_time+nb_time<shortestTime[nb_node]){
                    shortestTime[nb_node] = curr_time+nb_time;
                    paths[nb_node] = paths[curr_node];
                    pq.push({shortestTime[nb_node],nb_node});
                }
                else if(curr_time+nb_time==shortestTime[nb_node]){
                    paths[nb_node] += paths[curr_node];
                    paths[nb_node]%=mod;
                }
            }
        }
        return paths[n-1];
    }
};