class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),e=nums[n-1],j=n-2;
        while(j>=0){
            if(e>nums[j]){
                reverse(nums.begin()+j,nums.end());
                return;
            }
            --j;
        }
        reverse(nums.begin(),nums.end());
        return;
    }
};