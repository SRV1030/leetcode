class Solution {
public:
    int longestBeautifulSubstring(string w) {
        int res = 0;
        for (int i = 0, j = 0; i < w.size(); ++i) {
            if (w[i] == 'a') {
                int cnt = 0;
                for (j = i + 1; j < w.size() && w[j - 1] <= w[j]; ++j)
                    cnt += w[j - 1] < w[j];
                if (cnt == 4)
                    res = max(res, j - i);
                i = j - 1;
            }
        }
        return res;
    }
};