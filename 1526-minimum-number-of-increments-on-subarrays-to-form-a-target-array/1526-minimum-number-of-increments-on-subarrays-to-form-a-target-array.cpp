class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int sum = target[0];
        for(int index = 1; index < target.size();  ++index)
            sum += max(0, target[index] - target[index - 1]);
        return sum;
    }
};