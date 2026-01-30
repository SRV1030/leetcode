class Solution {
public:
    string intToRoman(int num) {
        vector<int> decimals = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> romans = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string romanValue;
        int divisorIndex = decimals.size() - 1;
        while(num > 0){
            int decimal = num / decimals[divisorIndex];
            num %= decimals[divisorIndex];
            while(decimal > 0){
                romanValue += romans[divisorIndex];
                --decimal;
            }
            --divisorIndex;
        }
        return romanValue;
    }
};