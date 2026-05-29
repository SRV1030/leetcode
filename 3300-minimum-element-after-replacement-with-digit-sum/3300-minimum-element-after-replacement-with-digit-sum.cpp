class Solution {
    int getSum(int num){
        int sum = 0;
        while(num){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for(auto& num : nums)
            mn = min(mn, getSum(num));
        return mn;
    }
};