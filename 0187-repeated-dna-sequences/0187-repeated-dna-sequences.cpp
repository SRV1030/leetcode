class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> fr;
        for(int index = 0; index + 10 <= s.size(); ++index)
            fr[s.substr(index, 10)]++;
        vector<string> result;
        for(auto& [key, value] : fr){
            if(value > 1)
                result.push_back(key);
        }
        return result;
    }
};