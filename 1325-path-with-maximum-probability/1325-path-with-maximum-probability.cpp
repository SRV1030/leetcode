class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end_node) {
        vector<vector<pair<int,double>>>g(n);
        for(int i=0;i<edges.size();++i){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        vector<double>prob(n,0.0);
        prob[start]=1.0;
        while(!pq.empty()){
            int cn=pq.top().second;
            pq.pop();
            for(auto&i:g[cn]){
                if(prob[cn]*i.second>prob[i.first]){
                    prob[i.first]=prob[cn]*i.second;
                    pq.push({prob[i.first],i.first});
                }
            }
        }
        return prob[end_node];
    }
};