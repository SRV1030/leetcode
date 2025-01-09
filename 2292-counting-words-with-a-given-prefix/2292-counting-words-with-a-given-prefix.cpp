class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0,np=pref.size();
        for(auto&i:words){
            int ni=i.size();
            if(ni<np)continue;
            if(i.substr(0,np)==pref)++c;
        }
        return c;
    }
};