class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringBucket;
        for(auto&str : strs){
            string key = str;
            sort(key.begin(), key.end());
            stringBucket[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& [_, stringArr] : stringBucket)
            result.push_back(stringArr);
        return result;
    }
};