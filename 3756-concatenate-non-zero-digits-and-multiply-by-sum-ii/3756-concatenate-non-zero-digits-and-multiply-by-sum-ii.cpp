class Solution {
    vector<long long> pow10;
    int size;
    const int MOD = 1e9 + 7;
public:
    void fils10s(){
        pow10[0] = 1;
        for(int ind = 1; ind <= size; ++ind){
            pow10[ind] = (pow10[ind - 1] * 10) % MOD;
        }
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        size = s.size();
        pow10.resize(size + 1);
        fils10s();
        vector<long long> prefixSum(size + 1), concat(size + 1), count(size + 1);
        for(int ind = 0; ind < size; ++ind){
            int dg = s[ind] - '0';
            prefixSum[ind + 1] = (prefixSum[ind] + dg) % MOD;
            concat[ind + 1] = dg ? (concat[ind] * 10 + dg) % MOD : concat[ind];
            count[ind + 1] = dg ? (count[ind] + 1) : count[ind];
        }
        vector<int> res;
        for(auto& query : queries){
            int l = query[0], r = query[1] + 1;
            long long sum = (prefixSum[r] - prefixSum[l]) % MOD;
            long long len = (count[r] - count[l]) % MOD;
            long long num = (concat[r] - (concat[l] * pow10[len]) % MOD + MOD) % MOD;
            res.push_back((num * sum) % MOD);
        }
        return res;
    }
};