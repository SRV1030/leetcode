class Solution {
public:
    bool isPos(vector<vector<int>>& tasks, int energy){
        for(auto& task : tasks){
            if(task[1] > energy)
                return false;
            energy -= task[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        long long low = 0, high = 0;
        sort(tasks.begin(), tasks.end(),[](auto& a, auto& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        for(auto& task : tasks){
            low = max(low, 1ll * task[1]);
            high += task[1];
        }

        while(low < high){
            long long mid = (low + high) / 2;
            if(isPos(tasks, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};