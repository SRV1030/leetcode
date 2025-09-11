class Solution {
public:
    bool isVowel(char x){
        x = tolower(x);
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x =='u';
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for(auto& character : s){
            if(isVowel(character))
                vowels.push_back(character);
        }
        sort(vowels.begin(), vowels.end());
        int index = 0;
        for(auto& character : s){
            if(isVowel(character))
                character = vowels[index++];
        }
        return s;
    }
};