class Solution {
public:
    int getIntWithUniqueDigits(int upperLimit, int numberOfDigits) {
        // Recursively calculate the number of numbers with unique digits
        return numberOfDigits == 0
                   ? 1
                   : getIntWithUniqueDigits(upperLimit, numberOfDigits - 1) *
                         (upperLimit - numberOfDigits + 1);
    }

    int numDupDigitsAtMostN(int n) {
        vector<int> digits;
        
        // Convert the number `n` to its digits and reverse them
        for (int i = n + 1; i > 0; i /= 10)
            digits.push_back(i % 10);
        reverse(digits.begin(), digits.end());
        
        int ans = 0;
        int numberOfDigits = digits.size();
        
        // Count valid numbers that are smaller than `n` by the number of digits
        for (int place = 1; place < numberOfDigits; ++place)
            ans += 9*getIntWithUniqueDigits(9, place-1);
        
        unordered_set<int> seen;
        
        // Process each digit from left to right
        for (int place = 0; place < numberOfDigits; ++place) {
            // Loop over digits smaller than the current digit
            for (int digit = place > 0 ? 0 : 1; digit < digits[place]; ++digit) {
                if (!seen.count(digit)) {
                    // Count the valid numbers formed from the remaining digits
                    ans += getIntWithUniqueDigits(9 - place, numberOfDigits - place - 1);
                }
            }
            
            // If we've already seen this digit, break, as further numbers are invalid
            if (seen.count(digits[place])) {
                break;
            }
            
            seen.insert(digits[place]);
        }
        
        // Return the result as n - ans (numbers with duplicates)
        return n - ans;
    }
};
