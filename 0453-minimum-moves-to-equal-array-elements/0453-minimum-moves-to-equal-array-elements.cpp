class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(),nums.end()),diffFromMin=0;
        for(auto&i:nums)diffFromMin+=(i-minNum);
        return diffFromMin;
    }
};