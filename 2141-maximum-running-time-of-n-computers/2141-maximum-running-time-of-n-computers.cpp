class Solution {
public:
    long long maxRunTime(int numberOfComputers, vector<int>& batteries) {
        long long totalCharge = accumulate(batteries.begin(), batteries.end(), 0ll);
        priority_queue<int> batteriesMaxHeap(batteries.begin(), batteries.end());
        while(batteriesMaxHeap.top() > (totalCharge/numberOfComputers)){
            totalCharge -= batteriesMaxHeap.top();
            batteriesMaxHeap.pop();
            numberOfComputers--;
        }
        return totalCharge / numberOfComputers;
    }
};