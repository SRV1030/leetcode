class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int groupSize) {
        map<int, int> fequencyMap;
        for(auto&num: nums)
            fequencyMap[num]++;
        int activeGroups = 0, previousNum = -1;
        queue<int> groupStartCounts;
        for(auto&[currentNum, frequency]: fequencyMap){
            if((activeGroups && currentNum > previousNum + 1) || activeGroups > frequency)
                return false;
            int newGroups = frequency - activeGroups;
            previousNum = currentNum;
            groupStartCounts.push(newGroups);
            activeGroups = frequency;
            if(groupStartCounts.size() == groupSize){
                activeGroups -= groupStartCounts.front();
                groupStartCounts.pop();
            }
        }
        return activeGroups == 0; 
    }
};