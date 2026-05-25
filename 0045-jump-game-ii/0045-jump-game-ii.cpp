class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, mx = 0, cur = 0;
        for(int index = 0; index < nums.size() - 1; ++index){
            mx = max(mx, index + nums[index]);
            if(cur == index){
                cur = mx;
                ++jumps;
            }
        }
        return jumps;
    }
};