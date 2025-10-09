class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> endTime(skill.size());
        for(auto& potion : mana){
            long long wait = 0, timeTaken = 0;
            for(int index = 0; index < skill.size(); index++){
                wait = max(wait, endTime[index] - timeTaken);
                timeTaken += potion * skill[index];
                endTime[index] = timeTaken;
            }
            for(auto& time : endTime)
                time += wait;
        }
        return endTime.back();
    }
};