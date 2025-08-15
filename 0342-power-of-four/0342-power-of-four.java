public class Solution {
    public boolean isPowerOfFour(int num) {
        return ((num & (num - 1)) == 0) && num % 3 == 1;
    }
}

// https://leetcode.com/problems/power-of-four/submissions/1736144192/?envType=daily-question&envId=2025-08-15