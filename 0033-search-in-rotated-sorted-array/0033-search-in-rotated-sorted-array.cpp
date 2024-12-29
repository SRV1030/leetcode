class Solution {
public:
    int search(vector<int>& nums, int tg) {
        int l=0,h=size(nums)-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==tg) return m;
            if(nums[l]<=nums[m]){
                if(nums[l]<=tg && tg<=nums[m]) h=m-1;
                else l=m+1;
            }
            else{
                if(nums[m]<=tg && tg<=nums[h]) l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};