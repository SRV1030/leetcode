class Solution {
    long long LOCAL_MIN = -1e18;
    vector<vector<vector<long long>>> dp;
public:
    long long getMax(vector<int>& nums1, vector<int>& nums2, int i1, int i2,int k){
        if(k <= 0)
            return 0;
        if(i1 >= nums1.size() || i2 >=nums2.size())
            return LOCAL_MIN;
        long long&  result = dp[i1][i2][k];
        if(result == LONG_MIN){
            result = getMax(nums1, nums2, i1, i2 + 1, k);
            result = max(result, getMax(nums1, nums2, i1 + 1, i2, k));
            result = max(result, getMax(nums1, nums2, i1 + 1, i2 + 1, k));
            result = max(result, 1ll * nums1[i1] * nums2[i2] + getMax(nums1, nums2, i1 + 1, i2 + 1, k - 1));
        }
        return result;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        dp = vector<vector<vector<long long>>> (nums1.size(), vector<vector<long long>>(nums2.size(), vector<long long>(k + 1, LONG_MIN)));
        return getMax(nums1, nums2, 0, 0, k);
    }
};