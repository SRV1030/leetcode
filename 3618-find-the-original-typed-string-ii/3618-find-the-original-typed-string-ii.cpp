class Solution {
    const int MOD = 1e9 + 7;
public:
    int possibleStringCount(string word, int k) {
        vector<int> groups;
        int frequency = 1, size = word.size();
        for(int index = 1; index < size; ++index){
            if(word[index] == word[index - 1]){
                ++frequency;
            }
            else{
                groups.push_back(frequency);
                frequency = 1;
            }
        }
        groups.push_back(frequency);
        long long total = 1;
        for(auto& group: groups)
            total = (total * group) % MOD;
        if(k <= groups.size())
            return total;
        vector<int> memo(k);
        memo[0] = 1;
        for(auto& group: groups){
            vector<int> cache(k);
            long long sum = 0;
            for(int len = 0; len < k; ++len){
                if(len > 0) sum = (sum + memo[len - 1]) % MOD;
                if(len > group) sum = (sum - memo[len - group - 1]) % MOD;
                cache[len] = sum;
            }
            memo = cache;
        }
        long long invalid = 0;
        for (int s = 0; s < k; ++s)
            invalid = (invalid + memo[s]) % MOD;

        return (total - invalid + MOD) % MOD;
    }
};