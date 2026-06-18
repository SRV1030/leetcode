class Solution {
public:
    vector<vector<int>> memory;
    int sizeOfS, sizeOfP;
    bool isRegexMatch(string s, string p, int indexOfS, int indexOfP){
        if(indexOfP == sizeOfP)
            return indexOfS == sizeOfS;
        if(indexOfS > sizeOfS || indexOfP > sizeOfP)
            return false;
        int& match = memory[indexOfS][indexOfP];
        if(match == -1){
            bool firstMatch = s[indexOfS] == p[indexOfP] || p[indexOfP] == '.';
            if(indexOfP + 1 < sizeOfP && p[indexOfP + 1] == '*'){
                bool skip = isRegexMatch(s, p, indexOfS, indexOfP + 2);
                bool take = firstMatch && isRegexMatch(s, p, indexOfS + 1, indexOfP);
                match = skip || take;
            }
            else
                match = firstMatch && isRegexMatch(s, p, indexOfS + 1, indexOfP + 1);
        }
        return match;
    }
    bool isMatch(string s, string p) {
        sizeOfS = s.size();
        sizeOfP = p.size();
        memory = vector<vector<int>> (sizeOfS + 1, vector<int>(sizeOfP + 1, -1));
        return isRegexMatch(s, p, 0, 0);
    }
};