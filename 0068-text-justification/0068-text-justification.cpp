class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.size()==0) 
            return {};
        int startIndex = 0, currentStringSize = words[0].size();
        vector<string> fullJustifiesGrid;
        for(int index = 1; index < words.size(); index++){
            if(currentStringSize + words[index].size() + 1 <= maxWidth){
                currentStringSize += words[index].size() + 1;
            }
            else{
                fullJustifiesGrid.push_back(generateNthString(startIndex, index, currentStringSize, maxWidth, words));
                currentStringSize = words[index].size();
                startIndex = index;
            }
        }
        fullJustifiesGrid.push_back(generateEndString(startIndex,maxWidth,words));
        return fullJustifiesGrid;
    }
    string generateNthString(int startIndex,int endIndex,int stringLength,int maxWidth,vector<string>& words){
        string currentString = words[startIndex];
        for(int wordIndex = startIndex + 1; wordIndex < endIndex; wordIndex++){
            int spaces = (maxWidth - stringLength)/(endIndex - wordIndex);
            if((maxWidth - stringLength)%(endIndex - wordIndex))
                spaces ++;
            stringLength += spaces;
            currentString += string(spaces + 1,' ');
            currentString += words[wordIndex];
        }
        int remainingSpaces = maxWidth - currentString.size();
        if(remainingSpaces > 0)
            currentString+= string(maxWidth - currentString.size(), ' ');
        return currentString;
    }
    string generateEndString(int startIndex, int maxWidth,vector<string>& words){
        string currentString = words[startIndex];
        for(int wordIndex = startIndex + 1; wordIndex < words.size(); wordIndex++)
            currentString += " " + words[wordIndex];
        while(currentString.size() < maxWidth)
            currentString.push_back(' ');
        return currentString;
    }
};