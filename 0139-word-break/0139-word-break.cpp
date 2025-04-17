class Solution {
public:
    set<string>dictionary;
    int dp[301][301];
    bool segmentCheck(string s,int lo,int hi){
        if(lo>hi) return true;
        int &ans = dp[lo][hi];
        if(ans!=-1) return ans;
        for(int j=lo;j<=hi;j++){
            if(dictionary.count(s.substr(lo,j-lo+1)) && segmentCheck(s,j+1,hi)) return ans = 1; 
        }
        return ans=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dictionary=set<string>(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof(dp));
        return segmentCheck(s,0,s.size()-1);
    }
};