class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals = {intervals[0]};
        int numberOfIntervals = intervals.size();
        for(int interval = 1; interval < numberOfIntervals; ++interval){
            if(mergedIntervals.back()[1] >= intervals[interval][0]){
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[interval][1]);
            }
            else
                mergedIntervals.push_back(intervals[interval]);
        }
        return mergedIntervals;
    }
};