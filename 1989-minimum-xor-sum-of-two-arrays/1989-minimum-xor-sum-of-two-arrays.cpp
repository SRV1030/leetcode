class Solution {
public:
    int num1_size, num2_size;
    int dp[15][1 << 16];
    int findMnXorSum(vector<int>& nums1, vector<int>& nums2, int ind_1,
                     int mask_2) {
        if (ind_1 == num1_size)
            return 0;
        if (dp[ind_1][mask_2] != -1)
            return dp[ind_1][mask_2];
        int mn_sum = INT_MAX;
        for (int i = 0; i < num2_size; ++i) {
            if ((mask_2 & (1 << (i + 1))) == 0)
                mn_sum =
                    min(mn_sum,
                        (nums1[ind_1] ^
                            nums2[i]) + findMnXorSum(nums1, nums2, ind_1 + 1,
                                                    mask_2 | (1 << (i + 1))));
        }
        return dp[ind_1][mask_2] = mn_sum; 
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        num1_size = nums1.size();
        num2_size = nums2.size();
        memset(dp, -1, sizeof(dp));
        return findMnXorSum(nums1, nums2, 0, 0);
    }
};