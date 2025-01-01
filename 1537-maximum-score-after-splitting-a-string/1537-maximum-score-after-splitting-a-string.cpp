class Solution {
public:
    int maxScore(string s) {
        vector<int>l(s.size()),r(s.size());
        l[0]=s[0]=='0';
        r[s.size()-1]=s[s.size()-1]=='1';
        for(int i=1;i<s.size();++i){
            l[i]=l[i-1]+(s[i]=='0');
        }
        for(int i=s.size()-2;i>=0;--i){
            r[i]=r[i+1]+(s[i]=='1');
        }
        int mx=0;
        for(int i=1;i<s.size();++i){
            mx=max(mx,l[i-1]+r[i]);
        }
        return mx;
    }
};