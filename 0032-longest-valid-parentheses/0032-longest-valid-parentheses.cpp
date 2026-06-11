class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, maxValid = 0;
        for(auto& character : s){
            if(character == '(')
                ++open;
            else
                ++close;
            if(close > open)
                open = close = 0;
            else if(open == close)
                maxValid = max(maxValid, open + close);
        }
        open = close = 0;
        for(int index = s.size() - 1; index >= 0; --index){
            char character = s[index];
            if(character == '(')
                ++open;
            else
                ++close;
            if(close < open)
                open = close = 0;
            else if(open == close)
                maxValid = max(maxValid, open + close);
        }
        return maxValid;
    }
};