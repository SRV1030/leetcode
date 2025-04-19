class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>cities(n);
        for(auto&road:roads){
            cities[road[0]].insert(road[1]);
            cities[road[1]].insert(road[0]);
        }
        int mx = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) {
                mx=max(mx,(int)(cities[i].size()+cities[j].size()-(cities[i].count(j))));
            }
        return mx;
    }
};