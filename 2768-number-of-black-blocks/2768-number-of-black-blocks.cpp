class Solution {
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const noexcept {
            return ((size_t)p.first << 32) ^ (size_t)p.second;
        }
    };
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<pair<int, int>, long long, pair_hash> subMatrix;
        vector<vector<int>> directions = {{0, 0} , {0, -1}, {-1, 0}, {-1, -1}};

        for(auto& cord : coordinates){
            for(auto& dir : directions){
                int row = cord[0] + dir[0], col = cord[1] + dir[1];
                if (row < 0 || col < 0 || row >= m - 1 || col >= n - 1)
                    continue;
                subMatrix[{row, col}]++;
            }
        }
        vector<long long> result(5);
        result[0] = 1ll * (m - 1) * (n - 1) - subMatrix.size();
        for(auto&[key, value] : subMatrix){
            if(value >= 5)
                continue;
            result[value]++;
        }
        return result;
    }
};