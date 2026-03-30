class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int threes = n / 3;
        int remainder = n % 3;
        if(remainder == 1){
            --threes;
            remainder = 4;
        }
        else if(!remainder)
            remainder = 1;
        return pow(3, threes) * remainder;
    }
};