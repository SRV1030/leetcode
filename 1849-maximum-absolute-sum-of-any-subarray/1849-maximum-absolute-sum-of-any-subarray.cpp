class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum=INT_MIN,min_sum=INT_MAX,curr_max=0,curr_min=0;
        for(auto&num:nums){
            curr_max+=num;
            curr_min+=num;
            max_sum=max(max_sum,curr_max);
            min_sum=min(min_sum,curr_min);
            curr_max=max(0,curr_max);
            curr_min=min(0,curr_min);
        }
        return max(abs(max_sum),abs(min_sum));
    }
};