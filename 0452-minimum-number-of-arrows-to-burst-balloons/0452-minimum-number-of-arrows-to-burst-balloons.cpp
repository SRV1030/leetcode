class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int end = points[0][1];
        int count = 1;
        for(int ind = 1; ind < points.size(); ++ind){
            if(points[ind][0] <= end)
                end = min(end, points[ind][1]);
            else{
                ++count;
                end = points[ind][1];
            }
        }
        return count;
    }
};