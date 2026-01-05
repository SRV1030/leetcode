class Solution {
public:
    bool check(vector<int>& nums,int mid,int k){
        long long sum = 0, splits = 0;
        for(auto& num: nums){
            sum += num;
            if(sum > mid){
                sum = num;
                ++splits;
            }
            if(splits >= k)
                return false;
        }
        return splits < k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;
        for(auto& num : nums){
            low = max(low, 1ll * num);
            high += num;
        }
        while(low < high){
            long long mid = (low + high) / 2;
            if(check(nums, mid, k))
                high = mid;
            else 
                low = mid + 1;
        }
        return low;
    }
};