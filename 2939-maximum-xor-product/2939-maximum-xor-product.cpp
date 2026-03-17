class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const long long MOD = 1e9 + 7;
        for(int bit = n - 1; bit >= 0; --bit){
            long long mask = 1LL << bit;
            if((a & mask) == (b & mask)){
                a |= mask;
                b |= mask;
            }
            else{
                if(a > b){
                    b |= mask;
                    a &= (~mask);
                }
                else{
                    a |= mask;
                    b &= (~mask);
                }
            }
        }
        return ((a % MOD) * (b % MOD)) % MOD;
    }
};