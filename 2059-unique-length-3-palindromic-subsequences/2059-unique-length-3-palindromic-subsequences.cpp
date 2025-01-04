class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>f(26,-1),l(26,-1);
        int ans=0;
        for(int i=0;i<size(s);++i){
            int charInd = s[i]-'a';
            if(f[charInd]==-1) f[charInd]=i;
            l[charInd]=i;
        }
        for(int i=0;i<26;++i){
            if(f[i]==-1) continue;
            unordered_set<char>st;
            for(int k=f[i]+1;k<l[i];++k)st.insert(s[k]);
            ans+=st.size();
        }
        return ans;
    }
};