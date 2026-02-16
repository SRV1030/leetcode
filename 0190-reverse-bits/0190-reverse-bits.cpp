class Solution {
public:
    int reverseBits(int n) {
        int newVal = 0;
        for(int bit = 31; bit >= 0; --bit){
            newVal |= ((n & 1) << bit);
            n >>= 1;
        }
        return newVal;
    }
};