class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if(dividend == divisor)
            return 1;
        if((divisor==-1 && dividend==(1<<31)))
            return INT_MAX;
        bool sign = (dividend < 0) == (divisor < 0);
        long long quotient = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while(dividend >= divisor){
            int bit = 0;
            while(dividend > (divisor << (bit + 1)))
                ++bit;
            quotient += (1 << bit);
            dividend -= (divisor << bit);
        }
        if(quotient == (1 << 31) && sign)
            return INT_MAX;
        return sign ? quotient : -quotient;
    }
};