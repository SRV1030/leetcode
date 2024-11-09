class Solution {
public:
    long long minEnd(int n, int x) {
        long long s=x;
        while(--n) s = (s+1)|x;
        return s;
    }
};