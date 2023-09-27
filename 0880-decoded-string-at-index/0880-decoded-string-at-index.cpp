class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long sz=0;
        for(auto&c:s){
            if(isalpha(c))++sz;
            else sz*=c-'0';
        }
        for(int i=size(s)-1;i>=0;--i){
            k=k%sz;
            if(k==0 && isalpha(s[i])) return string(1,s[i]);
            if(isalpha(s[i]))--sz;
            else sz/=s[i]-'0';
        }
        return "";
    }
};