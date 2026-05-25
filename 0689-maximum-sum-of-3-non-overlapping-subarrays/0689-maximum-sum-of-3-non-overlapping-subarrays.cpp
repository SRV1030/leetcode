class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int W = n - k + 1;  // number of valid window starts

        // windowSum[i] = sum of nums[i..i+k-1], built with a sliding window
        vector<int> windowSum(W, 0);
        int s = 0;
        for (int i = 0; i < k; ++i) s += nums[i];
        windowSum[0] = s;
        for (int i = 1; i < W; ++i) {
            s += nums[i + k - 1] - nums[i - 1];
            windowSum[i] = s;
        }

        // left[i] = best window start in [0..i], smallest index breaks ties
        vector<int> left(W);
        int best = 0;
        for (int i = 0; i < W; ++i) {
            if (windowSum[i] > windowSum[best]) best = i;   // strict > keeps earlier on tie
            left[i] = best;
        }

        // right[i] = best window start in [i..W-1], smallest index breaks ties
        vector<int> right(W);
        best = W - 1;
        for (int i = W - 1; i >= 0; --i) {
            if (windowSum[i] >= windowSum[best]) best = i;  // >= moves best left on tie
            right[i] = best;
        }

        // Try each m as the middle window; left[m-k] and right[m+k] are its best partners
        vector<int> ans(3);
        int maxTotal = -1;
        for (int m = k; m <= W - 1 - k; ++m) {
            int l = left[m - k];
            int r = right[m + k];
            int total = windowSum[l] + windowSum[m] + windowSum[r];
            if (total > maxTotal) {
                maxTotal = total;
                ans = {l, m, r};
            }
        }
        return ans;
    }
};