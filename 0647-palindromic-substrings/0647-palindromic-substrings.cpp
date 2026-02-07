class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int index = 0; index < s.size(); ++index){
            int left = index, right = index;
            while(left >= 0 && right < s.size() && s[left--] == s[right++]){
                ++count;
            }
            left = index, right = index + 1;
            while(left >= 0 && right < s.size() && s[left--] == s[right++]){
                ++count;
            }
        }
        return count;
    }
};