class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        for(int i=1;i<nums.size();++i)nums[i]^=nums[i-1];
        vector<int> res;
        maximumBit-=1;
        for(int i=nums.size()-1;i>=0;--i){
            int msk = 1<<maximumBit,ans=0;
            while(msk>0){
                if((msk & nums[i])==0)ans|=msk;
                msk>>=1;
            }
            res.push_back(ans);
        }
        return res;
    }
};