class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        for(int i=1;i<nums.size();++i)nums[i]^=nums[i-1];
        vector<int> res;
        int msk = (1<<maximumBit)-1;
        for(int i=nums.size()-1;i>=0;--i){
            res.push_back(nums[i]^msk);
        }
        return res;
    }
};