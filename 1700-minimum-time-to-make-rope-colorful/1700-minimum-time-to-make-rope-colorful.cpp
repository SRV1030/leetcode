class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0, previousIndex = 0;
        for(int index = 1; index < neededTime.size(); ++index){
            if(colors[index] == colors[previousIndex]){
                if(neededTime[index] < neededTime[previousIndex]){
                    time += neededTime[index];
                    continue;
                }
                time += neededTime[previousIndex];
            }
            previousIndex = index;
        }
        return time;
    }
};