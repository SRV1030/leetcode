class Solution {
    int memo[101][101][101];
public:
    int solve(vector<int>& boxes, int l, int r, int k){
        if(l > r)
            return 0;
        int& res = memo[l][r][k];
        if(res == -1){
            for(int ind = l + 1; ind <= r; ++ind){
                if(boxes[ind] == boxes[l]){
                    ++l;
                    ++k;
                }
                else
                    break;
            }
            res = (k + 1) * (k + 1) + solve(boxes, l + 1, r, 0);
            for(int m = l + 1; m <= r; ++m){
                if(boxes[m] == boxes[l])
                    res = max(res, solve(boxes, l + 1, m - 1, 0) + solve(boxes, m, r, k + 1));
            }
        }
        return res;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(memo, -1, sizeof(memo));
        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};