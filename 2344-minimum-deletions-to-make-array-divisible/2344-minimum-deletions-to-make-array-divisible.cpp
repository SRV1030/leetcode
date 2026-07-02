class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = numsDivide[0];
        for(auto& num : numsDivide)
            gcd = __gcd(gcd, num);
        sort(nums.begin(), nums.end());
        for(int index = 0; index < nums.size(); ++index){
            if(gcd % nums[index]  == 0)
                return index;
        }
        return -1;
    }
};