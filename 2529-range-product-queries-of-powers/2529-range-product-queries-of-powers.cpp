class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long powerMod(int base, int exponent){
        if(!exponent)
            return 1;
        long long result = 1;
        for(; exponent > 0; exponent >>= 1){
            if(exponent % 2)
                result = (1ll * result * base) % MOD;
            base = (1ll * base * base) % MOD;
        }
        return result;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> binary;
        for(int bits = 0; n > 0; n >>= 1, ++bits){
            if(n % 2)
                binary.push_back(bits);
        }
        vector<int> result;
        for(int index = 1; index < binary.size(); ++index)
            binary[index] += binary[index - 1];
        for(auto& query: queries)
            result.push_back((powerMod(2, binary[query[1]] - (query[0] ? binary[query[0] - 1] : 0))) % MOD);
        return result;
    }
};