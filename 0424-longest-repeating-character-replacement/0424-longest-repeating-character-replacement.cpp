class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0, maxFrequency = 0;
        vector<int> frequencies(26);
        for(int left = 0, right = 0; right < s.size(); ++right){
            frequencies[s[right] - 'A']++;
            maxFrequency = max(frequencies[s[right] - 'A'], maxFrequency);
            int bridge = right - left + 1 - maxFrequency;
            if(bridge > k)
                frequencies[s[left++] - 'A']--;
            length = max(length, right - left + 1);
        }
        return length;
    }
};