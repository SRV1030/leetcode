class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string t="",reverse;
        for(auto&i:s){
            if(i!=' ')t+=i;
            else{
                if(t.size())words.push_back(t);
                t="";
            }
        }
        if(t.size())words.push_back(t);
        for(int i=words.size()-1;i>=1;i--)reverse+=words[i]+" ";
        reverse+=words[0];
        return reverse;
    }
};