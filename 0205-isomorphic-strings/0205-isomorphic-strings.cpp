class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> tToSMappings(256, -1), sToTMappings(256, -1);
        int sizeOfWord = s.size();
        for(int index = 0; index < sizeOfWord; index++){
            int charIndexOfS = s[index], charIndexOfT = t[index];
            if(tToSMappings[charIndexOfT] != -1 && tToSMappings[charIndexOfT] != charIndexOfS)
                return false;
            if(sToTMappings[charIndexOfS] != -1 && sToTMappings[charIndexOfS] != charIndexOfT)
                return false;
            sToTMappings[charIndexOfS] = charIndexOfT;
            tToSMappings[charIndexOfT] = charIndexOfS;
        }
        return true;
    }
};