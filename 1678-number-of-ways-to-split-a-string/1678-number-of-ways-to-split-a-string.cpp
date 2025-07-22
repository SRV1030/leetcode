class Solution {
public:
    int numWays(string s) {
        long long ones = 0, size = s.size(), prefixWays = 0, suffixWays = 0;
        const int MOD = 1e9 + 7;
        for(auto& bit: s)
            if(bit == '1')
                ++ones;
        if(!ones)
            return (1ll * (size - 2ll) * (size - 1ll) / 2) % MOD;
        if(ones % 3)
            return 0;
        int splittedOnes = ones / 3, runningOnesCount = 0;
        for(auto& bit: s){
            runningOnesCount += bit == '1';
            if(runningOnesCount == splittedOnes)
                prefixWays++;
            if(runningOnesCount == 2 * splittedOnes)
                suffixWays++;
        }
        return (1ll * prefixWays % MOD * suffixWays % MOD) % MOD;
    }
};