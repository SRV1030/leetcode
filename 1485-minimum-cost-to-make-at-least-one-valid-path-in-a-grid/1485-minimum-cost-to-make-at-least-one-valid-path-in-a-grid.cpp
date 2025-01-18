class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int x=t[1],y=t[2],v=t[0];
            for(int i=0;i<4;i++){
                int nx=x+dir[i][0],ny=y+dir[i][1];
                if(min(nx,ny)<0 || nx>=m || ny>=n) continue;
                int w = g[x][y]==i+1?0:1;
                if(dis[nx][ny]>w+dis[x][y]){
                    dis[nx][ny]=w+dis[x][y];
                    pq.push({dis[nx][ny],nx,ny});
                }
            }
        }
        return dis[m-1][n-1];
    }
};