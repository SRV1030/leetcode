class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int mx = 1, st = 0;
        for(int ind = 0; ind < size; ++ind){
            int l = ind, r = ind;
            while(l >= 0 && r < size && s[l] == s[r]){
                l--;
                r++;
            }
            int len = r - l - 1;
            if(len > mx){
                mx = len;
                st = l + 1;
            }
            l = ind, r = ind + 1;
            while(l >= 0 && r < size && s[l] == s[r]){
                l--;
                r++;
            }
            len = r - l - 1;
            if(len > mx){
                mx = len;
                st = l + 1;
            }
        }
        return s.substr(st, mx);
    }
};