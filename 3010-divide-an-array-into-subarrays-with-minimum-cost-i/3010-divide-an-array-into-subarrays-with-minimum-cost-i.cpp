class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for(int ind = 1; ind < nums.size(); ++ind){
            if(nums[ind] < m1){
                m2 = m1;
                m1 = nums[ind];
            }
            else
                m2 = min(m2, nums[ind]);
        }
        return nums[0] + m1 + m2;
    }
};