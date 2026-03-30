class Solution {
    vector<vector<int>> dp;
public:
    int solve(string s, int low, int high){
        if(low > high)
            return 0;
        
        if(low == high)
            return 1;
        
        int& minCuts = dp[low][high];
        
        if(minCuts == -1){
            minCuts = 1 + solve(s, low + 1, high);
            for(int ind = low + 1; ind <= high; ++ind){
                if(s[low] == s[ind])
                    minCuts = min(minCuts, solve(s, low + 1, ind - 1) + solve(s, ind, high));
            }
        }
        return minCuts;
    }
    int strangePrinter(string s) {
        dp = vector<vector<int>> (s.size() + 1, vector<int> (s.size() + 1, -1));
        return solve(s, 0, s.size() - 1);
    }
};