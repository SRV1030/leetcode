class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st(begin(bannedWords),end(bannedWords));
        int c=0;
        for(auto&i:message){
            if(st.count(i)) ++c;
            if(c==2)return true;
        }
        return false;
    }
};