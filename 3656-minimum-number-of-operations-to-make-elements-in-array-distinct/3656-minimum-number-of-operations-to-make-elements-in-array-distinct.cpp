class Solution {
public:
    bool isUnique(vector<int> nums){
        unordered_set<int>seen;
        for(auto&i:nums)
            if(!seen.insert(i).second) return false;
        return true;
    }
    int minimumOperations(vector<int> nums) {
        if(nums.size()==0 || isUnique(nums)) return 0;
        if(nums.size()<=3) return 1;
        return 1+minimumOperations(vector<int>(nums.begin()+3,nums.end()));
    }
};