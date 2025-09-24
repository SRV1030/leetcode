class Solution {
public:
    double myPow(double x, long long n) {
        if(!n)
            return 1;
        if(!x)
            return 0;
        double result = 1.0;
        bool isNeg = (n < 0);
        n = abs(n);
        while(n){
            if(n % 2){
                if(isNeg) 
                    result /= x;
                else
                    result *= x;
            }
            x *= x;
            n >>= 1;
        }
        return result;
    }
};