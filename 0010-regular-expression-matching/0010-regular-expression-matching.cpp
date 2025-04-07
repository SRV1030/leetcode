class Solution {
public:
    vector<vector<int>> dp;
    bool matchPattern(int i, int j, string s, string p) {
        if (j == p.length())
            return i == s.length();
        int &ans= dp[i][j];
        if (ans != -1)
            return ans;
        bool firstMatch = i<s.size() && (s[i] == p[j] || p[j] == '.');
        if (j+1<p.size() && p[j+1] == '*')
            return ans = matchPattern(i, j + 2, s, p) ||
                  (firstMatch && matchPattern(i + 1, j, s, p));
        else
            return ans = firstMatch && matchPattern(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return matchPattern(0, 0, s, p);
    }
};