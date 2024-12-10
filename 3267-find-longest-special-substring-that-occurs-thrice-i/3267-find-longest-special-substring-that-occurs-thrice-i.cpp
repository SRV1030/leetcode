class Solution {
public:
    int maximumLength(string s) {
        
        unordered_map<string,int>mp;
        int mx=-1,n=size(s);
        for(int i=0;i<n;++i){
            string curr;
            for(int j=i;j<n;++j){
                if(curr.empty() || curr.back()==s[j]){
                    curr.push_back(s[j]);
                    mp[curr]++;
                    if(mp[curr]>=3)mx=max(mx,(int)curr.size());
                }
                else break;
            }
        }
        return mx;
    }
};