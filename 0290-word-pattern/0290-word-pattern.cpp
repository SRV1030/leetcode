class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream str(s);
        string word;
        int ind = 0;
        unordered_map<char, string> mp;
        unordered_set<string> words;
        while(str >> word){
            // cout << word << " " << pattern[ind] << "\n";
            if(mp.count(pattern[ind])){
                if(mp[pattern[ind]] != word)
                    return false;
            }
            else{
                if(words.count(word))
                    return false;
                words.insert(word);
                mp[pattern[ind]] = word;
            }
            ++ind;
        }
        return ind == pattern.size();
    }
};