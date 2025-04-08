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
        int intVal = 0;
        for(int ind = 0 ;ind<s.size();++ind){
            int currentVal = getVal(s[ind]);
            if(ind+1<s.size()){
                int nextVal = getVal(s[ind+1]);
                if(nextVal>currentVal){
                    currentVal=nextVal-currentVal;
                    ++ind;
                }
            }
            intVal+=currentVal;
        }
        return intVal;
    }
};