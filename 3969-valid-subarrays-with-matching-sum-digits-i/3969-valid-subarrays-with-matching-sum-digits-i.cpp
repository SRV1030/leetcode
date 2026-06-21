class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        vector<long long> prefixSums(nums.size() + 1);
        int count = 0;
        for(int ind = 0; ind < nums.size(); ++ind){
            prefixSums[ind + 1] = prefixSums[ind] + nums[ind];
        }
        for(int ind = 0; ind <= nums.size(); ++ind){
            for(int nxt = ind + 1; nxt <= nums.size(); ++nxt){
                long long sum = prefixSums[nxt] - prefixSums[ind];
                int last = sum % 10;
                long long t = sum;
                while(t >= 10) t/=10;
                int first = t;
                if(first == x and last == x) 
                    count++;
            }
        }
        return count;
    }
};