class Solution {
    int size;
public:
    int rotationCount(vector<int>& nums){
        int k = nums[0];
        for(int cur = 1; cur < size; ++cur){
            if(nums[cur] != (k + cur) % size)
                return -1;
        }
        return k;
    }
    int minOperations(vector<int>& nums) {
        size = nums.size();
        int k = rotationCount(nums);
        if(k != -1)
            return k == 0 ? 0 : min(size - k, k + 2);
        vector<int> rev(nums.rbegin(), nums.rend());
        k = rotationCount(rev);
        if(k != -1)
            return min(k + 1, size - k + 1);
        return -1;
    }
};