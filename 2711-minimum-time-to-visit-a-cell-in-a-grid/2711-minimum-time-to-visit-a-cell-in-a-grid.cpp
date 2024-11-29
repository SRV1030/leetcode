class Solution {
public:
    int minimumTime(vector<vector<int>>& g) {
        if(g[0][1]>1 && g[1][0]>1) return -1;
        int m=g.size(),n=g[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>vis(m,vector<int>(n));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({0,0,0});
        vis[0][0]=1;
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                vector<int>cur=pq.top();
                pq.pop();
                if(cur[1]==m-1 && cur[2]==n-1) return cur[0];
                for(auto&d:dir){
                    int x=d[0]+cur[1],y=d[1]+cur[2];
                    if(min(x,y)<0 || x>=m || y>=n || vis[x][y]) continue;
                    vis[x][y] = 1;
                    int extra = (g[x][y]-cur[0])%2==0;
                    int finalTime = max(g[x][y]+extra,cur[0]+1);
                    pq.push({finalTime,x,y});
                }
            }
        }
        return -1;
    }
};