class Solution {
public:
    bool isVowel(char x){
        return x=='a' || x=='e' || x=='i' || x=='o' || x=='u';
    }
    long long atLeastK(string word, int k){
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        // Keep track of counts of vowels and consonants.
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        // Start sliding window.
        while (end < word.length()) {
            // Insert new letter.
            char newLetter = word[end];

            // Update counts.
            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            // Shrink window while we have a valid substring.
            while (vowelCount.size() == 5 and consonantCount >= k) {
                numValidSubstrings += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }

        return numValidSubstrings;
    }
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k)-atLeastK(word,k+1);
    }
};