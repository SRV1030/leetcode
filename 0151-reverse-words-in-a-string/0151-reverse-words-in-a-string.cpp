class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string t,ans;
        while(str>>t)ans.insert(0," "+t);
        return ans.substr(1);
    }
};