class Solution {
public:
    vector<long long> memory;
    int numberOfLaps;
    void findMinTimeWithoutTyreChange(vector<vector<int>>& tires, int& changeTime){
        for(auto& tire: tires){
            long long f = tire[0], r = tire[1];
            long long lastLapTime = f, totalLapTime = f, laps = 2;
            memory[1] = min(memory[1], f);
            while(lastLapTime * r < f + changeTime && laps <= numberOfLaps) {
                long long currentLapTime = lastLapTime * r;
                totalLapTime += currentLapTime;
                memory[laps] = min(memory[laps], totalLapTime);
                lastLapTime = currentLapTime;
                laps++;
            }
        }
    }

    void modifyMinTimeIncludingTyreChange(vector<vector<int>>& tires, int& changeTime){
        for(long long lap = 1; lap <= numberOfLaps; lap++){
            for(long long previousLap = 1; previousLap < lap; previousLap++){
                memory[lap] = min(memory[lap], changeTime + memory[previousLap] + memory[lap - previousLap]);
            }
        }
    }
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        numberOfLaps = numLaps;
        memory = vector<long long> (numberOfLaps + 1, LONG_MAX);
        memory[0] = 0;
        findMinTimeWithoutTyreChange(tires, changeTime);
        modifyMinTimeIncludingTyreChange(tires, changeTime);
        return memory[numLaps];
    }
};