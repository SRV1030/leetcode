class Solution {
public:
    bool isUnique(unordered_map<int,int>mp){
        for(auto&[k,v]:mp)
            if(v>1) return false;
        return true;
    }
    int minimumOperations(vector<int> nums) {
        unordered_map<int,int>mp;
        for(auto&i:nums)mp[i]++;
        if(isUnique(mp) || nums.size()==0) return 0;
        if(nums.size()<=3) return 1;
        return 1+minimumOperations(vector<int>(nums.begin()+3,nums.end()));
    }
};