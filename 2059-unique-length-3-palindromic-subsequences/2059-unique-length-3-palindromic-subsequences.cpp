class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstSeen(26, -1), lastSeen(26);
        for(int index = 0; index < s.size(); ++index){
            int charInd = s[index] - 'a';
            if(firstSeen[charInd] == - 1)   
                firstSeen[charInd] = index;
            lastSeen[charInd] = index;
        } 
        int count = 0;
        for(int letter = 0; letter < 26; ++letter){
            if(firstSeen[letter] == - 1)   
                continue;
            set<char> st;
            for(int index = firstSeen[letter] + 1; index < lastSeen[letter]; ++index)
                st.insert(s[index]);
            count += st.size();
        }
        return count;
    }
};