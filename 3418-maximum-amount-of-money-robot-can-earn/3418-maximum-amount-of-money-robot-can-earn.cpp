class Solution {
public:
    int dp[501][501][3]={};
    bool visited[501][501][3];
    int r,c;
    long long solve(vector<vector<int>>& cn,int i,int j,int k){
        if(i >= r || j >= c) return INT_MIN ;
        if(i==r-1 && j==c-1){
            if(cn[i][j]<0 && k<=1) return 0;
            return cn[i][j];
        }
        if(visited[i][j][k]) return dp[i][j][k];
        long long o1=INT_MIN,o2=INT_MIN;
        o1=cn[i][j]+solve(cn,i+1,j,k);
        o2=cn[i][j]+solve(cn,i,j+1,k);
        if(cn[i][j]<0 && k<=1){
            o1=max(o1,solve(cn,i+1,j,k+1));
            o2=max(o2,solve(cn,i,j+1,k+1));
        }
        visited[i][j][k]=1;
        return dp[i][j][k]=max(o1,o2);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp,-1,sizeof(dp));
        memset(visited , 0 , sizeof(visited)) ;
        r=coins.size(),c=coins[0].size();
        return solve(coins,0,0,0);
    }
};