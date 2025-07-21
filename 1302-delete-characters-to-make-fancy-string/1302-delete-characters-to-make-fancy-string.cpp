class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int size = s.size();
        for(int index = 0; index < size; ++index){
            if(index < size - 2 && s[index] == s[index + 1] && s[index + 1] == s[index + 2])
                continue;
            result.push_back(s[index]);
        }
        return result;
    }
};