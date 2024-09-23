class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>dt(begin(dictionary),end(dictionary));
        unordered_map<int,int>mp;
        int n=size(s);
        function<int(int)> dp = [&](int start){
            if(start==n) return 0;
            if(mp.count(start)) return mp[start];
            int ans = dp(start+1)+1;
            for(int i=start;i<n;++i){
                string t = s.substr(start,i-start+1);
                if(dt.count(t))ans=min(ans,dp(i+1));
            }
            return mp[start]=ans;
        };
        return dp(0);
    }
};