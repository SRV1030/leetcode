class Solution {
    int memo[301][27][27];
public:
    pair<int, int> getPos(int ch){
        return {ch / 6, ch % 6};
    }

    int getDist(int f, int ch){
        if(f == 26 || ch == 26)
            return 0;
        auto[x1, y1] = getPos(f);
        auto[x2, y2] = getPos(ch);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int f1, int f2, int ind){
        if(ind == word.size())
            return 0;
        int &res = memo[ind][f1][f2];
        if(res == -1){
            int ch = word[ind] - 'A';
            res = min(getDist(f1, ch) + solve(word, ch, f2, ind + 1), 
                        getDist(f2, ch) + solve(word, f1, ch, ind + 1));
        }
        return res;
    }
    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
        return solve(word, 26, 26, 0);
    }
};