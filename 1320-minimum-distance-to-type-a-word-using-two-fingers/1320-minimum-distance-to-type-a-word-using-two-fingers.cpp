class Solution {
    int memo[301][27][27];
public:
    pair<int, int> getpos(int ind){
        return {ind / 6, ind % 6};
    }
    int dist(int f, int ch){
        if(f == 26 || ch == 26)
            return 0;
        auto[x1, y1] = getpos(f);
        auto[x2, y2] = getpos(ch);
        return abs(x1 - x2) + abs(y1 -y2);
    }
    int solve(int ind, int f1, int f2, string& word){
        if(ind == word.size())
            return 0;
        
        int& res = memo[ind][f1][f2];
        if(res == -1){
            int ch = word[ind] - 'A';
            int m1 = dist(ch, f1) + solve(ind + 1, ch, f2, word);
            int m2 = dist(ch, f2) + solve(ind + 1, f1, ch, word);
            res = min(m1, m2);
        }
        return res;
    }
    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 26, 26, word);
    }
};