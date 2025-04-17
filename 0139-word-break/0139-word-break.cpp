class Solution {
public:
    set<string>dictionary;
    int dp[301];
    bool segmentCheck(string s,int lo){
        if(lo>=s.size()) return true;
        int &ans = dp[lo];
        if(ans!=-1) return ans;
        for(int j=lo;j<s.size();j++){
            if(dictionary.count(s.substr(lo,j-lo+1)) && segmentCheck(s,j+1)) return ans = 1; 
        }
        return ans=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dictionary=set<string>(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof(dp));
        return segmentCheck(s,0);
    }
};