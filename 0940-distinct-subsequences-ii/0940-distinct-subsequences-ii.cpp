class Solution {
    int MOD = 1e9 + 7;
    int size;
    vector<long long> memo;
    vector<int> previous;
public:
    long long count(string& s, int ind){
        if(ind < 0)
            return 1;
        
        long long& res = memo[ind];
        if(res == -1){
            res = (2LL * count(s, ind - 1)) % MOD;
            int prevInd = previous[ind];
            if(prevInd != -1){
                res = (res % MOD - count(s, prevInd - 1) % MOD + MOD) % MOD;
            }
        }
        return res;
    }
    int distinctSubseqII(string s) {
        size = s.size();
        memo = vector<long long>(size, -1);
        previous = vector<int>(size, -1);
        vector<int> lastInd(26, -1);
        for(int ind = 0; ind < size; ++ind){
            int chInd = s[ind] - 'a';
            previous[ind] = lastInd[chInd];
            lastInd[chInd] = ind;
        }
        return (count(s, size - 1) - 1 + MOD) % MOD;
    }
};