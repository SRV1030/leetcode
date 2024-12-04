class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,j=0;
        while(i<str1.size() && j<str2.size()){
            int dif = ((str2[j]-str1[i])+26)%26;
            if(dif<=1){
                i++;
                j++;
            }
            else i++;
        }
        return j==size(str2);
    }
};