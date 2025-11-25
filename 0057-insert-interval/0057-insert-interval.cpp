class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int start = 0, size = intervals.size();
        while(start < size && intervals[start][1] < newInterval[0]){
            result.push_back(intervals[start]);
            start++;
        }
        while(start < size && intervals[start][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[start][0]);
            newInterval[1] = max(newInterval[1], intervals[start][1]);
            start++;
        }
        result.push_back(newInterval);
        for(int index = start; index < size; ++index){
            result.push_back(intervals[index]);
        }
        return result;
    }
};