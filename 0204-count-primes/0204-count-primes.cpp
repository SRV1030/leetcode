class Solution {
public:
    int seive(int n){
        if(n <= 2)
            return 0;
        int count = 0;
        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;
        for(int num = 2; num < n; ++num){
            if(primes[num]){
                for(int nxt = num * 2; nxt < n; nxt += num)
                    primes[nxt] = 0;
            }
        }
        for(int ind = 2; ind < n; ++ind)
            if(primes[ind])
                ++count;
        return count;
    }
    int countPrimes(int n) {
        return seive(n);
    }
};