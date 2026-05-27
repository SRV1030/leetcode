class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> lc,uc;
        for(auto& ch : word){
            if(ch >= 'a' && ch <= 'z'){
                int ind = ch - 'a';
                if(uc[ind])
                    lc[ind] = 0;
                else
                    lc[ind] = 1;
            }
            else{
                int ind = ch - 'A';
                uc[ind] = 1;
            }
        }
        lc &= uc;
        return lc.count();
    }
};