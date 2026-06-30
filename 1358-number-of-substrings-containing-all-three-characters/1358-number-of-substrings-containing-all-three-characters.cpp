class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int> frequency;
        int count = 0;
        for(int start = 0, index = 0; index < s.size(); ++index){
            frequency[s[index]]++;
            while(frequency.size() == 3){
                count += (s.size() - index);
                frequency[s[start]]--;
                if(!frequency[s[start]])
                    frequency.erase(s[start]);
                ++start;
            }
        }
        return count;
    }
};