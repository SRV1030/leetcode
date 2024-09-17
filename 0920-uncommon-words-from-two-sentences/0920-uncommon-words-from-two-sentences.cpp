class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream str1(s1),str2(s2);
        vector<string> ans;
        unordered_map<string,int>mp;
        string w;
        while(str1>>w)++mp[w];
        while(str2>>w)++mp[w];
        for(auto&[k,v]:mp)
            if(v==1)ans.push_back(k);
        return ans;
    }
};