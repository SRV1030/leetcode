class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int len = 0;
        for(int left = 0, right = 0; right < s.size(); ++right){
            if(lastIndex.count(s[right]) && left <= lastIndex[s[right]]){
                left = lastIndex[s[right]] + 1;
            }
            len = max(len, right - left + 1);
            lastIndex[s[right]] = right;
        }
        return len;
    }
};