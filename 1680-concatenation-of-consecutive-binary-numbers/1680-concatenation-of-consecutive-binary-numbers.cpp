class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0, MOD = 1e9 + 7, len = 0;
        for(int ind = 1; ind <= n; ++ind){
            if((ind & (ind - 1)) == 0){
                ++len;
            }
            res = ((res << len) % MOD + ind) % MOD;
        }
        return res;
    }
};