class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int count = 0, res = 0;
        int ind = 0;
        for(; ind < s.size() && s[ind] == '1'; ++ind);
        for(; ind < s.size(); ++ind){
            if(s[ind] == '1')
                ++count;
            else{
                res += count;
                count = 0;
            }
        }
        return res + count;
    }
};