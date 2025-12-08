class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high)
            return low % 2;
        low = low % 2 ? low : low + 1;
        high = high % 2 ? high : high - 1;
        int total = (high - low + 1);
        return (total / 2) + (total % 2);
    }
};