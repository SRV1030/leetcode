class Solution {
public:
    int numMatchingSubseq(string superSet, vector<string>& words) {
        vector<vector<int>> charToIndexMap(26);
        int sizeOfSuperSet = superSet.size();
        for(int index = 0;  index < sizeOfSuperSet; index++){
            int charIndex = superSet[index] - 'a';
            charToIndexMap[charIndex].push_back(index);
        }
        unordered_set<string> existing;
        int countSubset = 0;
        for(auto& word: words){
            if(existing.count(word)){
                countSubset++;
                continue;
            }
            int position = -1, notfound = 0;
            for(auto& letter: word){
                int charIndex = letter - 'a';
                vector<int> indices = charToIndexMap[charIndex];
                if(!indices.size()) {
                    notfound = 1;
                    break;
                };
                auto newPosition = upper_bound(indices.begin(),indices.end(),position);
                if(newPosition==indices.end()) {
                    notfound = 1;
                    break;
                };
                position = *newPosition;
            }
            if(!notfound) {
                ++countSubset;
                existing.insert(word);
            }
        }
        return countSubset;
    }
};