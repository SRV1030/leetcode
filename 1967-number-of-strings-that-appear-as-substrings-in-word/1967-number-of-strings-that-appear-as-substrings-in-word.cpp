class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int c=0;
        for(auto& i:patterns){
            if(word.find(i)!=string::npos) c++;
        }
        return c;
    }
};