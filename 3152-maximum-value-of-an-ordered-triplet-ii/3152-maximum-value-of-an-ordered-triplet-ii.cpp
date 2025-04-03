class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>left_max,right_max;
        int curr_left=nums[0],curr_right=nums[n-1];
        long long mx=0;
        for(auto&i:nums){
            left_max.push_back(curr_left);
            curr_left=max(curr_left,i);
        }
        for(int i=n-2;i>=0;i--){
            right_max.push_back(curr_right);
            curr_right=max(curr_right,nums[i]);
        }
        for(int i=1;i<n-1;i++)
            mx=max(mx,(long long)(left_max[i]-nums[i])*(long long)right_max[n-i-2]);
        return mx;
    }
};