class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> frequencies;
        for(auto& num : nums)
            frequencies[num]++;
        int sum = 0;
        for(auto&[key, frequency] : frequencies){
            if(frequency % k)
                continue;
            sum += frequency * key;
        }
        return sum;
    }
};