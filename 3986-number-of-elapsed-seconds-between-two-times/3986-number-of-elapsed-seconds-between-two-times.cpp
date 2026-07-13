class Solution {
public:
    long long timeToSec(string& startTime){
        return stoi(startTime.substr(0, 2)) * 60 * 60 + stoi(startTime.substr(3, 2)) * 60 + stoi(startTime.substr(6, 2));
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        long long st = 0, et = 0;
        st = timeToSec(startTime);
        et = timeToSec(endTime);
        return et - st;
    }
};