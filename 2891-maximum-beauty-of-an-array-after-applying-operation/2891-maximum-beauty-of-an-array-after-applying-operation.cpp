class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int mx=0;
        for(int i=0,j=0;j<nums.size();++j){
            while(i<=j && nums[j]-nums[i]>2*k)++i;
            mx=max(mx,j-i+1);
        }
        return mx;
    }
};