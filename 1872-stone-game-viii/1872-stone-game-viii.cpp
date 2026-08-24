class Solution {
    vector<int> prefixStones;
    int size;
    vector<int> memo;

public:
    int a_b(int ind) {
        if(ind == size - 1)
            return prefixStones[ind + 1];

        int& res = memo[ind];

        if(res == INT_MIN) {
            res = max(
                prefixStones[ind + 1] - a_b(ind + 1),
                a_b(ind + 1)
            );
        }

        return res;
    }

    int stoneGameVIII(vector<int>& stones) {
        size = stones.size();

        prefixStones = vector<int>(size + 1);
        memo = vector<int>(size + 1, INT_MIN);

        for(int ind = 0; ind < size; ++ind)
            prefixStones[ind + 1] =
                prefixStones[ind] + stones[ind];

        return a_b(1);
    }
};