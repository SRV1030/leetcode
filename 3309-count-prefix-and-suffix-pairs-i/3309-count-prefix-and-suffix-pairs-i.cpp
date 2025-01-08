class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size();++i)
            for(int j=i+1;j<words.size();++j){
                if(i==j) continue;
                int ni=words[i].size(),nj=words[j].size();
                if(ni>nj) continue;
                if(words[j].substr(0,ni) == words[i] && words[j].substr(nj-ni)==words[i])++c;
            }
        return c;
    }
};