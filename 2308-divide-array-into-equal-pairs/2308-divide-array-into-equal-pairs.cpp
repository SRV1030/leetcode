class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>fr;
        for(auto&i:nums)fr[i]++;
        for(auto&[k,v]:fr)if(v%2) return false;
        return true;
    }
};