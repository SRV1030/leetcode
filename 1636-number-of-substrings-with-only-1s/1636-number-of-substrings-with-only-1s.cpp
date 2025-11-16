class Solution {
public:
    int numSub(string s) {
        long long oc = 0, res = 0, mod = 1e9 + 7;
        for(int right = 0; right < s.size(); ++right){
            if(s[right] == '1'){
                oc = (oc + 1) % mod;
                res = (oc + res) % mod;
            }
            else
                oc = 0;
        }
        return res % mod;
    }
};