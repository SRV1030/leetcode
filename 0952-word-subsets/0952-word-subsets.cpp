class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f(26);
        for(int i=0;i<words2.size();++i){
            vector<int>t(26);
            for(auto&j:words2[i])
                t[j - 'a']++;
            for(int i=0;i<26;++i)f[i]=max(f[i],t[i]);
        }
        vector<string> ans;
        for (auto& i : words1) {
            vector<int> f1(26);
            for (auto& j : i)
                f1[j - 'a']++;
            bool consists = 1;
            for (int k = 0; k < 26; ++k)
                if (f[k] > f1[k]) {
                    consists = 0;
                    break;
                }
            if (consists)
                ans.push_back(i);
        }
        return ans;
    }
};