class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1001);
        int mx = 0;
        for(auto& trip : trips){
            int start = trip[1], end = trip[2];
            mx = max(mx, end);
            road[start] += trip[0];
            road[end] -= trip[0];
        }
        if(road[0] > capacity)
            return false;
        for(int pos = 1; pos <= mx; ++pos){
            road[pos] += road[pos - 1];
            if(road[pos] > capacity)
            return false;
        }
        return true;
    }
};