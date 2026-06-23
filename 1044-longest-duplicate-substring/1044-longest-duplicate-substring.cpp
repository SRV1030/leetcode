class Solution {
    const int BASE = 31;
    const int MOD = 1e9 + 7;
    int size;
    vector<long long> prefixHash, power;
    void fillRollingHash(string &s){
        size = s.size();
        prefixHash.resize(size + 1);
        power.assign(size + 1, 1);
        for(int ind = 0; ind < size; ++ind){
            power[ind + 1] = (power[ind] * BASE) % MOD;
            prefixHash[ind + 1] = (prefixHash[ind] * BASE + (s[ind] - 'a' + 1)) % MOD;
        }
    }
    int getHash(string &s, int lo, int hi){
        return (prefixHash[hi + 1] - (prefixHash[lo] * power[hi - lo + 1]) % MOD + MOD) % MOD;
    }
    pair<int, bool> isPos(string &s, int len){
        unordered_map<long long, vector<int>> seen;
        for(int ind = 0; ind + len <= size; ++ind){
            long long hash = getHash(s, ind, ind + len - 1);
            if(seen.count(hash)){
                for(int prev : seen[hash]){
                    if(s.compare(ind, len, s, prev, len) == 0)
                        return {ind, true};
                }
            }
            seen[hash].push_back(ind);
        }
        return {-1, false};
    }
public:
    string longestDupSubstring(string s) {
        int lo = 0, hi = s.size(), ind = -1, len = 0;
        fillRollingHash(s);
        while(lo <= hi){
             int mid = lo + (hi - lo) / 2;
            auto state = isPos(s, mid);
            if(state.second){
                ind = state.first;
                len = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ind == -1 ? "" : s.substr(ind, len);
    }
};