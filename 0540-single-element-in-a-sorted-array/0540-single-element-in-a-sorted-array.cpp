class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0,e=size(nums)-1;
        while(s<e){
            int m=(s+e)/2;
            if(m%2)m--;
            if(nums[m]!=nums[m+1]) e=m;
            else s=m+2;
        }
        return nums[s];
    }
};