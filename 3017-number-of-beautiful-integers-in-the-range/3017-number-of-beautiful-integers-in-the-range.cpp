class Solution {
public:
    bool HasEqualEvenOddDigits(int n)
    {
        int evenCount = 0, oddCount = 0;
        while (n > 0)
        {
            int digit = n % 10;
            n /= 10; 
            if (digit % 2 == 0) 
                evenCount++; 
            else 
                oddCount++; 
        }
        return evenCount > 0 && oddCount > 0 && evenCount == oddCount;
    }
    int numberOfBeautifulIntegers(int low, int high, int k)
    {
        if (high < 10) 
        {
            return 0; 
        }

        int count = 0; 
        // Find the first number greater than or equal to 'low' that is 
        low = ((low - 1) / k + 1) * k;
        for (int i = low; i <= high; i += k)
        { 
            if (HasEqualEvenOddDigits(i)) 
            {
                count++; 
            }
            if (i >= 100000000) 
            {
                break; 
            }
        }
        return count;
    }
};