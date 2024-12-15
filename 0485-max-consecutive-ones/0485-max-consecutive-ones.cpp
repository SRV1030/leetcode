class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,mx=0;
        for(auto&i:nums){
            if(i)++c;
            else{
                mx=max(mx,c);
                c=0;
            }
        }
        mx=max(mx,c);
        return mx;
    }
};