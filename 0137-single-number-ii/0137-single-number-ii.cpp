class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bit = 0; bit < 32; ++bit){
            int numberOfSetBits = 0;
            for(auto& num : nums){
                numberOfSetBits += ((num >> bit) & 1);
            }
            numberOfSetBits %= 3;
            ans |= (numberOfSetBits << bit);
        }
        return ans;
    }
};