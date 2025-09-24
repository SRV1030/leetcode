class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0)
            return "0";

        string result;

        // If signs are different, prepend '-'
        if ((numerator < 0) ^ (denominator < 0))
            result.push_back('-');

        // Work with absolute values
        numerator = llabs(numerator);
        denominator = llabs(denominator);

        long long quotient = numerator / denominator;
        long long remainder = numerator % denominator;

        result += to_string(quotient);

        if (remainder == 0)
            return result;

        result.push_back('.');
        unordered_map<long long, int> decimalToIndex;

        while (remainder != 0) {
            if (decimalToIndex.count(remainder)) {
                result.insert(result.begin() + decimalToIndex[remainder], '(');
                result.push_back(')');
                return result;
            }
            decimalToIndex[remainder] = result.size();

            remainder *= 10;
            quotient = remainder / denominator;
            remainder = remainder % denominator;

            result += to_string(quotient);
        }

        return result;
    }
};
