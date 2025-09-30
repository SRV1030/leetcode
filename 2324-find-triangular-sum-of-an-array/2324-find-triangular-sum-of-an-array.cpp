class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(!nums.size())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        vector<int> temp;
        for(int index = 1; index < nums.size(); ++index)
            temp.push_back((nums[index] + nums[index - 1])%10);
        return triangularSum(temp);
    }
};