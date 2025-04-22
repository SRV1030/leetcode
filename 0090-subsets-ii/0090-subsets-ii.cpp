class Solution {
public:
    vector<vector<int>> powerSet;
    void generateAllPossibleSubsets(vector<int>subset,vector<int>& nums,int ind){
        powerSet.push_back(subset);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i-1]==nums[i]) continue;
            subset.push_back(nums[i]);
            generateAllPossibleSubsets(subset,nums,i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        generateAllPossibleSubsets({},nums,0);
        return powerSet;
    }
};