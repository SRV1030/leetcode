class Solution {
    int memory[10004];
    const int LOCAL_MAX = 1e9;
public:
    int findMinSq(int n){
        if(n <= 3)
            return n;
        int& mn = memory[n];
        if(mn == -1){
            mn = LOCAL_MAX;
            for(int num = 1; num * num <= n; ++num)
                mn = min(mn, 1 + findMinSq(n - num * num));
        }
        return mn;
    }
    int numSquares(int n) {
        memset(memory, -1, sizeof(memory));
        return findMinSq(n);
    }
};