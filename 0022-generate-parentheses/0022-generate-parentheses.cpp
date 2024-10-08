class Solution {
public:
    vector<string> ans;
    void generate(int o,int c,string t=""){
        if(c==0)ans.push_back(t);
        else{
            if(c>o)generate(o,c-1,t+')');
            if(o>0)generate(o-1,c,t+'(');
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n,n);
        return ans;
    }
};