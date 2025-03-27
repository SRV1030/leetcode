class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int xCount = 0, x = nums[0], n = nums.size();
        for (auto& i : nums) {
            if (i == x)
                xCount++;
            else
                xCount--;
            if (xCount == 0) {
                x = i;
                xCount = 1;
            }
        }
        xCount = 0;
        int count = 0;
        for (auto& i : nums)
            xCount += (i == x);
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                ++count;
                if (count * 2 > (i + 1) && (xCount - count) * 2 > (n - i - 1))
                    return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int minimumIndex(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int> fmp, tfmp;
//         for (auto& i : nums)
//             fmp[i]++;
//         for (int i = 0; i < n; i++) {
//             tfmp[nums[i]]++;
//             if ((tfmp[nums[i]] * 2) > (i + 1) &&
//                 (((fmp[nums[i]] - tfmp[nums[i]]) * 2 )> (n - i - 1)))
//                 return i;
//         }
//         return -1;
//     }
// };