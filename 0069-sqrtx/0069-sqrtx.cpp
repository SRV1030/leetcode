class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x / 2;
        while(low <= high){
            int mid = (low + high) / 2;
            int sqr = mid * mid;
            if(sqr == x)
                return mid;
            if(sqr < x){
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return high;
    }
};