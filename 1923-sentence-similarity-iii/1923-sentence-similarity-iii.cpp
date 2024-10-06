class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1,s2;
        stringstream st1(sentence1),st2(sentence2);
        string w;
        while(st1>>w)s1.push_back(w);
        while(st2>>w)s2.push_back(w);
        int n1=size(s1),n2=size(s2),i=0;
        if(n1>n2) return areSentencesSimilar(sentence2,sentence1);
        while(i<n1 && s1[i]==s2[i])++i;
        while(n1>0 && s1[n1-1]==s2[n2-1]){
            --n1;
            --n2;
        }
        return n1<=i;
    }
};