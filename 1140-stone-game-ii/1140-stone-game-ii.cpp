class Solution {
    vector<int> prefixPiles;
    vector<vector<int>> memo; 
    int size;
public:
    int solve(int ind, int m){
        if(ind >= size)
            return 0;
        int& res = memo[ind][m];
        if(res == -1){
            int maxPicks = min(size - ind, 2 * m);
            int totalSum = prefixPiles[size] - prefixPiles[ind];
            for(int pick = ind; pick < ind + maxPicks; ++pick){
                int remaing = pick - ind + 1;
                res = max(res, totalSum - solve(pick + 1, max(m, remaing)));
            }
        }
        return res;
    }
    int stoneGameII(vector<int>& piles) {
        size = piles.size();
        prefixPiles.resize(size + 1);
        memo = vector<vector<int>>(size + 1, vector<int>(2 * size + 1, -1));
        for(int ind = 0; ind < size; ++ind){
            prefixPiles[ind + 1] += prefixPiles[ind] + piles[ind];
        }
        return solve(0, 1);
    }
};