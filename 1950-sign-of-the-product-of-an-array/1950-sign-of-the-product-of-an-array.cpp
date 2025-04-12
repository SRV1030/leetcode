class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0,size = nums.size();
        for(auto&i:nums){
            if(!i) return 0;
            if(i<0) ++neg;
        }
        return neg%2==0?1:-1;

    }
};