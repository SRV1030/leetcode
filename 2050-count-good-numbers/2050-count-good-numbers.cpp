class Solution {
public:
    int MOD = 1e9 + 7;
    long long pow(long long a, long long b) {
        if (!b)
            return 1;
        long long res = 1;
        while (b > 0) {
            if (b % 2)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res % MOD;
    }
    int countGoodNumbers(long long n) {
        if (n == 1)
            return 5;
        long long half = n / 2;
        return (pow(5, n - half) * pow(4, half)) % MOD;
    }
};