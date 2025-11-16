class Solution {
public:
    int numSub(string s) {
        long long oc = 0, res = 0, mod = 1e9 + 7;
        for(int right = 0; right < s.size(); ++right){
            if(s[right] == '1')
                oc = (oc + 1) % mod;
            else{
                res += (oc * (oc + 1)) / 2;
                res %= mod;
                oc = 0;
            }
        }
        if(oc)
            res += (oc * (oc + 1)) / 2;
        return res % mod;
    }
};