class Solution {
    vector<vector<int>> result;
    int size;
public:
    void generate(vector<int> nums, int low){
        if(low == size - 1){
            result.push_back(nums);
            return;
        }
        for(int ind = low; ind < size; ++ind){
            if(ind != low && nums[ind] == nums[low])
                continue;
            swap(nums[ind], nums[low]);
            generate(nums, low + 1);
            // swap(nums[ind], nums[low]);
            // seen.insert(nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size = nums.size();
        generate(nums, 0);
        return result;
    }
};