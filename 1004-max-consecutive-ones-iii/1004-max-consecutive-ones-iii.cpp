class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zc = 0, oc = 0, mx = 0;
        for(int left = 0, right = 0; right < nums.size(); ++right){
            if(!nums[right])
                ++zc;
            while(left < right && zc > k){
                if(!nums[left++])
                    --zc;
            }
            if(zc <= k)
                mx = max(mx , right - left + 1);
        }
        return mx;
    }
};