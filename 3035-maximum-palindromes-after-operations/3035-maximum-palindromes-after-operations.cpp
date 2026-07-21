class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> freq(26), lengths;
        int ones = 0, pairs = 0, pals = 0, size = words.size();
        for(auto& word : words){
            for(auto& ch : word)
                freq[ch - 'a']++;
            lengths.push_back(word.size());
        }
        sort(lengths.begin(), lengths.end());
        for(auto& fr : freq){
            pairs += fr / 2;
        }
        for(int index = 0; index < size; ++index){
            int requiredChars = lengths[index] / 2;
            if(pairs - requiredChars < 0)
                return index;
            pairs -= requiredChars;
        }
        return size;
    }
};