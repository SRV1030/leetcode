class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> appear(128);
        int count = 0;
        for(auto& ch : word){
            if(appear[ch])
                continue;
            if(ch >= 'A' && ch<= 'Z'){
                if(appear[ch + 32])
                    ++count;
            }
            else if(ch >= 'a' && ch<= 'z'){
                if(appear[ch - 32])
                    ++count;
            }
            appear[ch] = 1;
        }
        return count;
    }
};