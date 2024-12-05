class Solution {
public:
    double myPow(double x, long long n) {
        if(!x) return 0.0;
        if(!n) return 1.0;
        double res = 1.0;
        bool sign = n>=0;
        n=abs(n);
        while(n){
            if(n%2){
                if(sign)res*=x;
                else res/=x;
            }
            x*=x;
            n>>=1;
        }
        return res;
    }
};