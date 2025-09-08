class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128, -1);
        int left = 0, length = 0;
        for(int index = 0; index < s.size(); ++index){
            int charIndex = s[index];
            if(lastSeen[charIndex] >= left){
                left = lastSeen[charIndex] + 1;
            }
            lastSeen[charIndex] = index;
            length = max(length, index - left + 1);
        }
        return length;
    }
};