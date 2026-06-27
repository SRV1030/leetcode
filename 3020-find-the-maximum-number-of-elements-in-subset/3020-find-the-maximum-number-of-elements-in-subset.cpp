class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for(auto& num : nums)
            freq[num]++;
        long long res = 1;
        if(freq.count(1)){
            int fr = freq[1];
            res = fr % 2 ? fr : fr - 1;
            freq.erase(1); 
        }
        int mxBase = 31623;
        for(auto fr : freq){
            long long key = fr.first, value = fr.second;
            long long root = sqrt(key);
            if(root * root == key && freq.count(root) && freq[root] > 1)
                continue;
            
            long long len = 0;
            while(key < mxBase && value > 1){
                len += 2;
                key *= key;
                value = freq.count(key) ? freq[key] : 0;
            }
            res = max(res, len + (freq.count(key) ? 1 : -1));
        }
        return res;
    }
};