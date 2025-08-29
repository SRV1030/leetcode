class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n1 = n / 2 , n2 = n - n1, m1 = m / 2, m2 = m - m1;
        return n1 * m2 + n2 * m1;
    }
};