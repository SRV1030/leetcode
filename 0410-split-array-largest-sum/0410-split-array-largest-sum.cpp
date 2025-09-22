class Solution {
public:
    bool checkMaxSum(vector<int>& nums, int k, int maxSum){
        int sum = 0;
        int subArrays = 0;
        for(auto& num: nums){
            sum += num;
            if(sum > maxSum){
                ++subArrays;
                sum = num;
            }
            if(subArrays > k)
                return false;
        }
        return subArrays < k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for(auto& num: nums){
            low = max(num, low);
            high += num;
        }
        while(low < high){
            int mid = (low + high) / 2;
            if(checkMaxSum(nums, k, mid))
                high = mid;
            else low = mid + 1;
        }
        return low;
    }
};