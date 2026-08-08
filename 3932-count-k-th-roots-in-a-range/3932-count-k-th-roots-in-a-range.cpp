class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1)
            return r - l + 1;
        int maxPow = pow(r , 1.0 / k) + 1, res = 0;
        for(int val = 0; val <= maxPow; ++val){
            long long y = pow(val, k);
            if(l <= y && y <= r)
                ++res;
        }
        return res;
     }
};