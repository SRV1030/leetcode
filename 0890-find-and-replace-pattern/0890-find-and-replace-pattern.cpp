class Solution {
public:
    string normalize(string& pattern){
        string text = "";
        unordered_map<char, int> mp;
        for(auto& ch : pattern){
            if(!mp.count(ch))
                mp[ch] = mp.size();
        }
        for(auto& ch : pattern){
            text.push_back('a' + mp[ch]);
        }
        return text;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string normalizedPattern = normalize(pattern);
        vector<string> res;
        for(auto& word : words){
            if(normalize(word) == normalizedPattern)
                res.push_back(word);
        }
        return res;
    }
};