class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int decimal = 0;
        for(auto& num : nums){
            decimal = ((decimal << 1) + num) % 5;
            result.push_back(decimal == 0);
        }
        return result;
    }
};