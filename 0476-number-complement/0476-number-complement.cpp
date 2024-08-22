class Solution {
public:
    int findComplement(int num) {
        return num^((1u<<(32-countl_zero((unsigned)num)))-1);
    }
};