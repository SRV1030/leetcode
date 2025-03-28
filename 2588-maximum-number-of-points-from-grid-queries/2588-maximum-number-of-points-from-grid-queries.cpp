class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), columnCount = grid[0].size(),
            querySize = queries.size();
        vector<int> result(querySize);
        vector<vector<int>> sortedQuery;
        const vector<vector<int>> DIRECTIONS = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < querySize; i++)
            sortedQuery.push_back({queries[i], i});
        sort(sortedQuery.begin(), sortedQuery.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<bool>> visited(rowCount,
                                     vector<bool>(columnCount, false));
        minHeap.push({grid[0][0], 0, 0});
        int totalCount = 0;
        visited[0][0]=true;
        for (auto query : sortedQuery) {
            int queryValue = query[0], queryIndex = query[1];
            while (!minHeap.empty() && minHeap.top()[0] < queryValue) {
                vector<int> top = minHeap.top();
                int currentGirdValue = top[0], currentRow = top[1],
                    currentColumn = top[2];
                minHeap.pop();
                totalCount++;
                for (auto& direction : DIRECTIONS) {
                    int nextRow = currentRow + direction[0],
                        nextColumn = currentColumn + direction[1];
                    if (min(nextRow, nextColumn) >= 0 && nextRow < rowCount &&
                        nextColumn < columnCount &&
                        !visited[nextRow][nextColumn]) {
                        visited[nextRow][nextColumn] = true;
                        minHeap.push(
                            {grid[nextRow][nextColumn], nextRow, nextColumn});
                    }
                }
            }
            result[queryIndex] = totalCount;
        }
        return result;
    }
};