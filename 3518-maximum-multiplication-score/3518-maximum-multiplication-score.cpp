class Solution {
public:
    long dp[5][1000001];
    long solve(vector<int>& a, vector<int>& b,int i,int j){
        if(i>=a.size()) return 0;
        if(j>=b.size()) return -1e11;
        if(dp[i][j]!=-1) return dp[i][j];
        long o1 = (long)a[i]*(long)b[j]+solve(a,b,i+1,j+1);
        long o2 = solve(a,b,i,j+1);
        return dp[i][j]=max(o1,o2);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));
        return solve(a,b,0,0);
    }
};