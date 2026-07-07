class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int currentWeight = 0, day = 1;
        for(auto& weight : weights){
            currentWeight += weight;
            if(currentWeight > capacity){
                currentWeight = weight;
                ++day;
            }
        }
        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for(auto& weight : weights){
            high += weight;
            low = max(low, weight);
        }
        while(low < high){
            int mid = (low + high) / 2;
            if(isPossible(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};