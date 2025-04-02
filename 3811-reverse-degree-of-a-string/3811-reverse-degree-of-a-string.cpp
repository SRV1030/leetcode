class Solution {
public:
    int reverseDegree(string s) {
        int sm=0;
        for(int i=0;i<s.size();i++){
            int ind  = i+1,revInd = 27-(s[i]-'a'+1);
            sm+=ind*revInd;
        }
        return sm;
    }
};