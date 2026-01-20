class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(auto& num : nums){
            if(num == 2)
                result.push_back(-1);
            else{
                int diffBit = ((num + 1) & (~num)) >> 1;
                result.push_back(num & (~diffBit));
            }
        }
        return result;
    }
};