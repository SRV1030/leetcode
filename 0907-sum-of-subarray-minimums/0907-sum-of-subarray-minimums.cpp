class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int size = arr.size();
        stack<int> simulator;
        vector<int> leftRange(size), rightRange(size);
        for(int index = 0; index < size; ++index){
            while(!simulator.empty() && arr[index] < arr[simulator.top()]){
                simulator.pop();
            }
            if(simulator.empty())
                leftRange[index] = index + 1;
            else
                leftRange[index] = index - simulator.top();
            simulator.push(index);
        }
        simulator = stack<int>();
        for(int index = size - 1; index >= 0; --index){
            while(!simulator.empty() && arr[index] <= arr[simulator.top()]){
                simulator.pop();
            }
            if(simulator.empty())
                rightRange[index] = size - index;
            else
                rightRange[index] = simulator.top() - index;
            simulator.push(index);
        }
        long long result = 0;
        for(int index = 0; index < size; ++index){
            long long numberOfSubArrays = (leftRange[index] * rightRange[index]) % MOD;
            long long total = (numberOfSubArrays * arr[index]) % MOD;
            result = (result + total) % MOD;
        }
        return result;
    }
};