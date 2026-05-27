class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int total = 1 << nums.size();
        vector<vector<int>> subsets;
        for(int mask = 0; mask < total; ++mask){
            vector<int> subset;
            for(int bit = 0; bit < nums.size(); ++bit){
                if(mask & (1 << bit))
                    subset.push_back(nums[bit]);
            }
            subsets.push_back(subset);
        }
        return subsets; 
    }
};