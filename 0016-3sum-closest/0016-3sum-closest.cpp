class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int closest = 1e9;
        sort(nums.begin(), nums.end());
        for(int ind = 0; ind < size - 2; ++ind){
            int left = ind + 1, right = size - 1;
            while(left < right){
                int sum = nums[ind] + nums[left] + nums[right];
                if(abs(closest - target) > abs(sum - target))
                    closest = sum;
                if(sum > target)
                    --right;
                else
                    ++left;
            }
        }
        return closest;
    }
};