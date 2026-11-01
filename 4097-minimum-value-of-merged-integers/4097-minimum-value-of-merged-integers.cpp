class Solution {
public:
    int dgPow(int n){
        return (n == 0) ? 1 : log10(abs(n)) + 1;
    }
    int minMergedInteger(vector<int>& nums) {
        int mn = 1e9;
        for(int ind = 0; ind < nums.size() - 1; ind += 2){
            int multiplier = pow(10, dgPow(nums[ind + 1]));
            mn = min(mn, nums[ind] * multiplier + nums[ind + 1]);
        }
        return mn;
    }
};