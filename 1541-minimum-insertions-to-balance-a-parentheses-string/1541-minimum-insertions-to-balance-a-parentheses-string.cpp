class Solution {
public:
    int minInsertions(string s) {
        int open = 0, close = 0;
        for(auto& ch : s){
            if(ch == '('){
                if(close % 2){
                    ++open;
                    --close;
                }
                close += 2;
            }
            else{
                close--;
                if(close < 0){
                    ++open;
                    close = 1;
                }
            }
        }
        return open + close;
    }
};