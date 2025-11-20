class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), greater<>());
        int x = 1e9, y = 1e9;
        int size = 0;
        for(auto&interval : intervals){
            int left = interval[0], right = interval[1];
            int need = 2;
            if(x <= right)
                --need;
            if(y <= right)
                --need;
            if(!need)
                continue;
            if(need == 1){
                if(x != left)
                    y = left;
                else
                    y = left + 1;
                if(x > y)
                    swap(x, y);
                ++size;
            }
            else{
                x = left;
                y = left + 1;
                size += 2;
            }
        }
        return size;
    }
};