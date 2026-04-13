class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDist = INT_MAX;
        for(int index = 0; index < nums.size(); ++index){
            if(nums[index] == target){
                minDist = min(minDist, abs(start - index));
            }
        }
        return minDist;
    }
};