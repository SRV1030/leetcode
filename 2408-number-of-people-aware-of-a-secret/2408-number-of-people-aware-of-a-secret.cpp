class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> aware(n + 1);
        long long int total = 1, MOD = 1e9 + 7, spread = 0;
        aware[0] = 1;
        for(int day = 1; day < n; ++day){
            if(day >= delay)
                spread += aware[day - delay];
            if(day >= forget){
                long long forgot = aware[day - forget];
                spread = (spread - forgot + MOD) % MOD;  
                total = (total - forgot + MOD) % MOD;
            }
            spread %= MOD;
            total = (total + spread) % MOD;
            aware[day] = spread;
        }
        return total;
    }
};