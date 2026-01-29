class Solution {
    vector<int> memo;
    vector<vector<bool>> pal;
public:
    int getMax(string &s, int k, int start){
        if(start >= s.size()) return 0;
        int &res = memo[start];
        if(res != -1) return res;

        res = getMax(s, k, start + 1); // skip

        for(int end = start + k - 1; end < s.size(); ++end){
            if(pal[start][end]){
                res = max(res, 1 + getMax(s, k, end + 1));
            }
        }
        return res;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        memo.assign(n, -1);
        pal.assign(n, vector<bool>(n, false));

        // Precompute palindromes
        for(int i = 0; i < n; ++i) pal[i][i] = true;
        for(int len = 2; len <= n; ++len){
            for(int i = 0; i + len - 1 < n; ++i){
                int j = i + len - 1;
                pal[i][j] = (s[i] == s[j]) && (len == 2 || pal[i+1][j-1]);
            }
        }

        return getMax(s, k, 0);
    }
};
