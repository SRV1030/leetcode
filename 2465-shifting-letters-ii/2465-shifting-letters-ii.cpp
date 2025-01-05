class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> pf(s.size());
        for(auto&i:shifts){
            int x = i[2]?1:-1;
            pf[i[0]]=pf[i[0]]+x;
            if(i[1]+1<s.size())pf[i[1]+1]=pf[i[1]+1]-x;
        }
        int cur = 0;
        for(int i=0;i<pf.size();i++){
            cur+=pf[i];
            cur%=26;
            if(cur<0)cur+=26;
            int inc = (cur+s[i]-'a')%26;
            s[i]=('a'+inc);
        }
        return s;
    }
};