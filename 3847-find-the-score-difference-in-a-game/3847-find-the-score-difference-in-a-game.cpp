class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int fp = 0, sp = 0;
        int play = 1;
        for(int ind = 0; ind < nums.size(); ++ind){
            if((ind + 1) % 6 == 0)
                play ^= 1;
            if((nums[ind] % 2))
                play ^= 1;
            if(play)
                fp += nums[ind];
            else
                sp += nums[ind];
        }
        return fp - sp;
    }
};