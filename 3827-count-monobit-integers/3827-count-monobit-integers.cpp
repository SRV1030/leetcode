class Solution {
public:
    int countMonobit(int n) {
        return bit_width((unsigned int)n + 1);
    }
};