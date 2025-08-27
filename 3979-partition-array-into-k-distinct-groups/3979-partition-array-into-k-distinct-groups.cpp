class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int size = nums.size();
        if(size % k != 0)
            return 0;
        int groups = size / k;
        int freq[100001] = {0};
        for(int x: nums){
            if (++freq[x] > groups) return 0;
        }
        return 1;
    }
};