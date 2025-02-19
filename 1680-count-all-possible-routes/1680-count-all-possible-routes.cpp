class Solution {
private:
vector<vector<int>>dp;
public:
    int md = 1e9+7;
    Solution(){
        dp=vector<vector<int>>(101,vector<int>(201,-1));
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        if(fuel<0) {
            return 0;
        }
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int pos=(start==finish);
        for(int i=0;i<locations.size();++i){
            if(i==start) continue;
            pos = (pos%md + countRoutes(locations,i,finish,fuel-abs(locations[i]-locations[start]))%md)%md;
        }
        return dp[start][fuel]=pos;
    }
};