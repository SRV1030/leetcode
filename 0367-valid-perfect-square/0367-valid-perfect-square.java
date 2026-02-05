class Solution {
    public boolean isPerfectSquare(int num) {
        if(num==1) return true;
        int low = 1, high = num / 2;
        while(low <= high){
            int mid = (low + high) / 2;
            long sqr = (long) mid * mid;
            if(sqr == num)
                return true;
            if(sqr > num)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
}