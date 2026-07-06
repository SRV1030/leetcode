class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int end = intervals[0][1], count = 0;
        for(int ind = 1; ind < intervals.size(); ++ind){
            if(intervals[ind][0] <= end){
                if(intervals[ind][1] > end)
                    end = intervals[ind][1];
                else
                    ++count;
            }
            else
                end = intervals[ind][1];
        }
        return intervals.size() - count;
    }
};