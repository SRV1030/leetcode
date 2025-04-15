class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0, prevInd = 0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[prevInd]){
                if(neededTime[i]<neededTime[prevInd]) {
                    time+=neededTime[i];
                    continue;
                }
                else time+=neededTime[prevInd];
            }
            prevInd = i;
        }
        return time;
    }
};