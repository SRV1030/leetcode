class Solution {
public:
    int getSum(int a, int b) {
        //sum = (a ^ b) + (a & b) << 1;
        while(b){
            int c = a & b;
            a ^= b;
            b = c << 1;
        }
        return a;
    }
};