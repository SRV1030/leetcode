class Solution {
public:
    vector<vector<string>> ans;
    vector<string>t;
    bool isPal(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(string s,int i){
        if(i==size(s)){
            ans.push_back(t);
        }
        else{
            for(int j=i;j<=size(s);++j){
                if(isPal(s,i,j)){
                    t.push_back(s.substr(i,j-i+1));
                    solve(s,j+1);
                    t.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};