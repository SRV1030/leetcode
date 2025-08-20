class Solution {
public:
    void countPalindrome(int index, string& s, int offset, int& count){
        int left = index, right = index + offset;
        while(left >= 0 && right < s.size() && s[left--] == s[right++]){
            ++count;
        }
    }
    int countSubstrings(string& s) {
        int count = 0;
        for(int index = 0; index < s.size(); ++index){
            countPalindrome(index, s, 0, count);
            countPalindrome(index, s, 1, count);
        }
        return count;
    }
};