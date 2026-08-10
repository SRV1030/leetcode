class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        for(long long place = 1; place <= n; place *= 10){
            long long lo = n % place;
            long long cur = (n / place) % 10;
            long long hi = n / (place * 10);

            if(cur == 0){
                count += hi * place;
            }
            else if(cur == 1){
                count += hi * place + lo + 1;
            }
            else{
                count += (hi + 1) * place;
            }
        }
        return count;
    }
};