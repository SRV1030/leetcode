class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        for (auto& i : arr)
            i %= 2;
        vector<int> dpOdd(n), dpEven(n);
        if (arr[0])
            dpOdd[0] = 1;
        else
            dpEven[0] = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i]) {
                dpOdd[i] = (1 + dpEven[i - 1]) % mod;
                dpEven[i] = dpOdd[i - 1];
            } else {
                dpOdd[i] = dpOdd[i - 1];
                dpEven[i] = (1 + dpEven[i - 1]) % mod;
            }
        }
        int oddCount = 0;
        for (auto& i : dpOdd)
            oddCount = (oddCount % mod + i % mod) % mod;
        return oddCount;
    }
};