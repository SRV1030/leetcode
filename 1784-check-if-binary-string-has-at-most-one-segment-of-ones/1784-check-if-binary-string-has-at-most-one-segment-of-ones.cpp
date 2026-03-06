class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s == "1")
            return true;
        for(int ind = 1; ind < s.size(); ++ind)
            if(s[ind] == '1' && s[ind - 1] == '0')
                return false;
        return true;
    }
};