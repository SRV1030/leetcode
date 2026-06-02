class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int sizeOfNums = nums.size();
        vector<int> decrements(sizeOfNums + 1);
        for(auto& query: queries){
            decrements[query[0]] += 1;
            decrements[query[1] + 1] -= 1;
        }
        for(int decrementIndex = 1; decrementIndex < sizeOfNums; decrementIndex++)
            decrements[decrementIndex] += decrements[decrementIndex - 1];
        for(int index = 0; index < sizeOfNums; index++)
            if(decrements[index] < nums[index])
                return false;
        return true;
    }
};