class Solution {
    vector<int> memo;
    int size;
public:
    int a_b(int ind, vector<int>& stoneValue){
        if(ind >= size)
            return 0;
        int& res = memo[ind];
        if(res == -1){
            res = stoneValue[ind] - a_b(ind + 1, stoneValue);
            if(ind + 1 < size)
                res = max(res, stoneValue[ind] + stoneValue[ind + 1] - a_b(ind + 2, stoneValue));
            if(ind + 2 < size)
                res = max(res, stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2] - a_b(ind + 3, stoneValue));
        }
        return res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        size = stoneValue.size();
        memo = vector<int>(size, -1);
        int res = a_b(0, stoneValue);
        return res == 0 ? "Tie" : res > 0 ? "Alice" : "Bob";
    }
};