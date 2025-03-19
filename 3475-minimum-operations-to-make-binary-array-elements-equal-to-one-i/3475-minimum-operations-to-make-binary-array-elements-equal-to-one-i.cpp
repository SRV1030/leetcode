class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(int i=2;i<nums.size();i++){
            if(!nums[i-2]){
                ++c;
                nums[i-2]^=1;
                nums[i-1]^=1;
                nums[i]^=1;
            }
        }
        return accumulate(begin(nums),end(nums),0)==nums.size()?c:-1;
    }
};