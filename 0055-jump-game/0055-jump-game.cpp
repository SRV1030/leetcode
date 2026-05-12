class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for(int index = 0; index < nums.size(); ++index){
            if(index > maxJump)
                return false;
            maxJump = max(maxJump, index + nums[index]);
        }
        return true;
    }
};