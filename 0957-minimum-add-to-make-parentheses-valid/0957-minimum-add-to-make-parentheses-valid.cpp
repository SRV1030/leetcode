class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int o=0,c=0;
        for(auto&i:s){
            if(i=='(')o++;
            else {
                if(o==0)++c;
                else --o;
            }
        }
        return c+o;
    }
};