class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = 1LL * cars * cars * ranks[0],ans=-1;
        while (low <=high) {
            long long mid = low + (high - low) / 2, carsRepaired = 0;
            for (auto rank : ranks) carsRepaired += sqrt(1.0 * mid / rank);
            if (carsRepaired < cars)
                low = mid + 1;
            else{
                ans=mid;
                high=mid-1;
            }
        }

        return ans;
    }
};