class Solution {
public:
    bool isVowel(char x){
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    bool doesAliceWin(string s) {
        int vowels = 0;
        for(auto& character : s)
            if(isVowel(character))
                ++vowels;
        return vowels;
    }
};