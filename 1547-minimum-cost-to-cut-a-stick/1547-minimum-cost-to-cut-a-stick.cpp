class Solution {
public:
    vector<vector<int>>dp;
    int findCost(vector<int>& cuts,int i,int j){
        if(i>j) return 0;
        int &ans = dp[i][j];
        if(ans!=-1) return ans;
        ans = INT_MAX;
        for(int k=i;k<=j;k++){
            ans = min(ans,cuts[j+1]-cuts[i-1]+findCost(cuts,i,k-1)+findCost(cuts,k+1,j));
        }
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        dp = vector<vector<int>>(m,vector<int>(m,-1));
        return findCost(cuts,1,m-2); 
    }
};