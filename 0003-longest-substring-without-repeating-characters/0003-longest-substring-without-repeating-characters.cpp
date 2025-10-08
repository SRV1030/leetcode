class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        int left = -1, length = 0;
        for(int right = 0; right < s.size(); ++right){
            if(left <= lastIndex[s[right]])
                left = lastIndex[s[right]] + 1;
            lastIndex[s[right]] = right;
            length = max(length, right - left + 1);
        }
        return length;
    }
};