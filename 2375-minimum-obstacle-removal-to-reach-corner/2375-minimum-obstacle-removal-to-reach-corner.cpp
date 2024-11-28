class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<int>> mnObs(m, vector<int>(n, INT_MAX));
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        mnObs[0][0]=grid[0][0];
        pq.push({mnObs[0][0],0,0});
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                vector<int>cur=pq.top();
                pq.pop();
                if(cur[1]==m-1 && cur[2]==n-1) return cur[0];
                for(auto&d:dir){
                    int x=d[0]+cur[1],y=d[1]+cur[2];
                    if(min(x,y)>=0 && x<m && y<n){
                        if(cur[0]+grid[x][y]<mnObs[x][y]){
                            mnObs[x][y]=cur[0]+grid[x][y];
                            pq.push({mnObs[x][y],x,y});
                        }
                    }
                }
            }
        }
        return mnObs[m-1][n-1];
    }
};