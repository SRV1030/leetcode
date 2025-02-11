class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s.size()<part.size()) return s;
        for(int i=0;i+part.size()-1<s.size();++i){
            if(s.substr(i,part.size())==part){
                s.erase(i,part.size());
                return removeOccurrences(s,part);
            }
        }
        return s;
    }
};