class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int days = rains.size();
        vector<int> ans(days, -1);
        unordered_map<int, int> lakeIndex;
        set<int> dryDay;
        for(int day = 0; day < days; ++day){
            if(!rains[day]){
                dryDay.insert(day);
                ans[day] = 1;
            }
            else{
                if(lakeIndex.count(rains[day])){
                    int previousDay = lakeIndex[rains[day]];
                    auto dryDayItr = dryDay.upper_bound(previousDay);
                    if(dryDayItr == dryDay.end())
                        return {};
                    ans[*dryDayItr] = rains[day];
                    dryDay.erase(dryDayItr);
                }
                lakeIndex[rains[day]] = day;
            }
        }
        return ans;
    }
};