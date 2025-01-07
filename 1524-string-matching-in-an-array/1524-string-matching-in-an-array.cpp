class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words.size();++j){
                if(i!=j && words[j].find(words[i])!=string::npos) ans.insert(words[i]);
            }
        }
        return vector<string>(begin(ans),end(ans));
    }
};