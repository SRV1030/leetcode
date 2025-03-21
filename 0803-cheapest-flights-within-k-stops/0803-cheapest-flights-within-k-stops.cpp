class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>g(n);
        for(auto& i:flights) g[i[0]].push_back({i[1],i[2]});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,int>>pq;
        pq.push({0,src});
        k+=1;
        while(!pq.empty() && k--){
            int n=pq.size();
            while(n--){
                int d=pq.front().first,s=pq.front().second;
                pq.pop();
                for(auto& i:g[s]){
                    if(dist[i.first]>d+i.second){
                        dist[i.first]=d+i.second;
                        pq.push({dist[i.first],i.first});
                    } 
                }                
            }
        }
        return dist[dst]==INT_MAX? -1:dist[dst];
    }
};