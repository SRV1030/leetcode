class Solution {
public:
    int jump(vector<int>& nums) {
        int farthestJump = 0, jumps = 0, farthestIndex = 0;
        for(int index = 0; index < nums.size() - 1; ++index){
            farthestJump = max(farthestJump, index + nums[index]);
            if(index == farthestIndex){
                ++jumps;
                farthestIndex = farthestJump;
            }
        }
        return jumps;
    }
};