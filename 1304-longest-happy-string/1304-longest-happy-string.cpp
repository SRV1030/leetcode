class Solution {
    char previousChar = '$', beforePreviousChar = '$';
    priority_queue<pair<char, int>> maxHeap;
public:
    void addCharacter(auto& character, auto& frequecy, string& longestString){
        longestString.push_back(character);
        frequecy--;
        if(frequecy)
            maxHeap.push({frequecy, character});
        beforePreviousChar = previousChar;
        previousChar = character;
    }
    string longestDiverseString(int a, int b, int c) {
        if(a)
            maxHeap.push({a, 'a'});
        if(b)
            maxHeap.push({b, 'b'});
        if(c)
            maxHeap.push({c, 'c'});
        string longestString = "";
        while(!maxHeap.empty()){
            auto[frequency, character] = maxHeap.top();
            maxHeap.pop();
            if(character == previousChar && previousChar == beforePreviousChar){
                if(maxHeap.empty())
                    return longestString;
                auto[nextFrequency, nextCharacter] = maxHeap.top();
                maxHeap.pop();
                maxHeap.push({frequency, character});
                addCharacter(nextCharacter, nextFrequency, longestString);
                continue;
            }
            addCharacter(character, frequency, longestString);
        }
        return longestString;
    }
};