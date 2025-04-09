class Solution {
public:
    vector<vector<char>> numToChar = {
        {},
        {},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };
    vector<string> allCombinations;
    void generateCombinations(string digits,string currentPattern,int index){
        if(index == digits.size()){
            allCombinations.push_back(currentPattern);
            return;
        }
        for(auto&character:numToChar[digits[index]-'0']) generateCombinations(digits,currentPattern+character,index+1);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        generateCombinations(digits,"",0);
        return allCombinations;
    }
};