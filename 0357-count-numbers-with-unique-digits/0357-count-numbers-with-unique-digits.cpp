class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n)
            return 1;
        int count = 10, a = 9, b = 9;
        while(--n && a > 0){
            b *= a;
            count += b;
            --a;
        }
        return count;
    }
};