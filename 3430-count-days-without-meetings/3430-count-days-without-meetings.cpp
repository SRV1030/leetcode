class Solution {
public:
    int countDays(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> mergedMeet;
        mergedMeet.push_back(meetings[0]);
        for(int i=1;i<meetings.size();i++){
            if(mergedMeet.back()[1]>=meetings[i][0])
                mergedMeet.back()[1]=max(mergedMeet.back()[1],meetings[i][1]);
            else mergedMeet.push_back(meetings[i]);
        }
        for(auto&i:mergedMeet)n-=(i[1]-i[0]+1);
        return n;
    }
};