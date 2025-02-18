class Solution {
public:
    bool isPal(string s, int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    vector<string> t;
    int n;
    void applyPartion(string s,int i){
        if(i==n){
            ans.push_back(t);
            return;
        }
        for(int j=i;j<n;++j){
            if(isPal(s,i,j)){
                t.push_back(s.substr(i,j-i+1));
                applyPartion(s,j+1);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        applyPartion(s,0);
        return ans;
    }
};