class Solution {
public:
    int getVal(char x){
        switch (x){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default: return 1000;
        }
    }
    int romanToInt(string s) {
        int res=0,n=s.length();
        for(int i=0;i<n;++i){
            int v1=getVal(s[i]);
            if(i+1<n){
                int v2=getVal(s[i+1]);
                if(v1>=v2)res+=v1;
                else {
                    res+=v2-v1;
                    i++;
                }
            }
            else res+=v1;
        }
        return res;
    }
};