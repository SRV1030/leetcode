class Solution {
    const int MOD = 1e9 + 7;
public:
    long long modPow(long long a, long long b){
        if(!b)
            return 1;
        long long res = 1;
        while(b > 0){
            if(b % 2)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res % MOD;
    }
    int countGoodNumbers(long long n) {
        long long oddPos = n / 2, evenPos = n - oddPos;
        return (modPow(5, evenPos) * modPow(4, oddPos)) % MOD;
    }
};