class Solution {
public:
    bool isVowel(char a){
        return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pf(size(words));
        for(int i=0;i<size(words);++i){
            pf[i]=(isVowel(words[i][0])&&isVowel(words[i][words[i].size()-1]));
            if(i>0)pf[i]+=pf[i-1];
        }
        vector<int> ans;
        for(auto&i:queries) ans.push_back(pf[i[1]]-(i[0]>0?pf[i[0]-1]:0));
        return ans;
    }
};