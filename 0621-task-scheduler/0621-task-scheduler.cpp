class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int jobFrequency[26] = {};
        int maxFrequencyCount = 0, maxFrequency = 0;
        for(auto& job: tasks){
            jobFrequency[job - 'A']++;
            if(jobFrequency[job - 'A'] == maxFrequency){
                maxFrequencyCount++;
            }
            else if(jobFrequency[job - 'A'] > maxFrequency){
                maxFrequency = jobFrequency[job - 'A'];
                maxFrequencyCount = 1;
            }
        }
        int partitionCount = maxFrequency - 1;
        int emptySlotsInPartition = n - (maxFrequencyCount - 1);
        int emptySlots = partitionCount * emptySlotsInPartition;
        int tasksLeft =  tasks.size() - maxFrequency * maxFrequencyCount;
        return tasks.size() + max(0, emptySlots - tasksLeft);
    }
};