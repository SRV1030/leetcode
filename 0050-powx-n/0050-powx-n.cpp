class Solution {
public:
    double myPow(double x, int n1) {
        double res = 1.0;
        if(!n1)
            return res;
        if(!x)
            return 0;
        bool isNeg = (n1 < 0);
        long n = abs(1ll * n1);
        while(n){
            if(n % 2){
                if(isNeg)
                    res /= x;
                else res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};