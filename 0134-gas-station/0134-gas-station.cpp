class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, sum = 0, start = 0;
        for(int index = 0; index < gas.size(); ++index){
            totalGas += gas[index];
            totalCost += cost[index];
            sum += gas[index] - cost[index];
            if(sum < 0){
                start = index + 1;
                sum = 0;
            }
        }
        if(totalGas < totalCost)
            return -1;
        return start;
    }
};