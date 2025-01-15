class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=0,t=__builtin_popcount(num2),s=0,msb=31;
        while(s<t){
            if((num1&(1<<msb)) || t-s>msb){
                x|=(1<<msb);
                ++s;
            }
            --msb;
        }
        return x;
    }
};