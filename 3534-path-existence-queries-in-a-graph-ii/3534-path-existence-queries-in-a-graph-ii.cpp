class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> numToIndex;
        const int LOG = 17;

        vector<vector<int>> sparseTree(n, vector<int>(LOG));

        for(int ind = 0; ind < n; ++ind)
            numToIndex.push_back({nums[ind], ind});
        sort(numToIndex.begin(), numToIndex.end());

        for(int left = n - 1, right = n - 1; left >= 0; --left){
            while(numToIndex[right][0] - numToIndex[left][0] > maxDiff)
                --right;
            int node = numToIndex[left][1];
            sparseTree[node][0] = numToIndex[right][1];
            for(int bit = 1; bit < LOG; ++bit)
                sparseTree[node][bit] = sparseTree[sparseTree[node][bit - 1]][bit - 1];
        }
        vector<int> result;

        for(auto& query : queries){
            int u = query[0], v = query[1];
            if(nums[u] > nums[v])
                swap(u, v);
            if(u == v){
                result.push_back(0);
                continue;
            }
            int target = nums[v];
            int steps = 0;
            for(int bit = LOG - 1; bit >= 0; --bit){
                if(nums[sparseTree[u][bit]] < target){
                    u = sparseTree[u][bit];
                    steps += (1 << bit);
                }
            }
            result.push_back((nums[sparseTree[u][0]] < target) ? -1 : steps + 1);
        }
        return result;
    }
};