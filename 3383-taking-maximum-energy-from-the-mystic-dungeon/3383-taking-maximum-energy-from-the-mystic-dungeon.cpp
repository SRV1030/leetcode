class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> memo(energy.size());
        int maxV = INT_MIN;
        for(int index  = energy.size() - 1; index >= 0 ; --index){
            memo[index] = energy[index] + (index + k < energy.size() ? memo[index + k] : 0);
            maxV = max(maxV, memo[index]);
        }
        return maxV;
    }
};