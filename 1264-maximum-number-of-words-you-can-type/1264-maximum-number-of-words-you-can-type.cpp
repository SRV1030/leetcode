class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream str(text);
        string word;
        bitset<26> mask;
        for(auto& character : brokenLetters){
            mask[character - 'a'] = 1;
        }
        int count = 0;
        while(str >> word){
            bool isBroken = false;
            for(auto& character : word){
                if(mask[character - 'a']){
                    isBroken = true;
                    break;
                }
            } 
            if(!isBroken)
                ++count;
        }
        return count;
    }
};