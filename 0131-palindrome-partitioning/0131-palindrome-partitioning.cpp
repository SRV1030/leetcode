class Solution {
public:
    bool isPal(string &s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    vector<vector<string>> result;
    vector<string> pal;
    int size;
    void gen(string &s, int index){
        if(index == size){
            result.push_back(pal);
            return;
        }
        for(int right = index; right < size; ++right){
            if(isPal(s, index, right)){
                pal.push_back(s.substr(index, right - index + 1));
                gen(s, right + 1);
                pal.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        size = s.size();
        gen(s, 0);
        return result;
    }
};