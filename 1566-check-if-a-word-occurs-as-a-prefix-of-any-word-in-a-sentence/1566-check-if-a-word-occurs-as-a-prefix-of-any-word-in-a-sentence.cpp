class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string w;
        stringstream str(sentence);
        int ans=1;
        while(str>>w){
            if(w.size()>=searchWord.size() && w.substr(0,searchWord.size())==searchWord) return ans;
            ++ans;
        }
        return -1;
    }
};