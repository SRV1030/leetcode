class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        int sum = 0, foundZero = 0;
        for(auto& num: unique){
            if(num > 0){
                sum += num;
            }
            else if(num == 0){
               foundZero = 1;
            }
        }
        if(sum == 0 && !foundZero)
            return *prev(unique.end());
        return sum;
    }
};