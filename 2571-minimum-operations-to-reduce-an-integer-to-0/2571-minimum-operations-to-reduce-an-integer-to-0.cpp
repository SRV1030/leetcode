class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        while(n){
            if((n & 3) == 3){
                ++n;
                ++res;
            }
            else{
                res += (n & 1);
                n >>= 1;
            }
        }
        return res;
    }
};