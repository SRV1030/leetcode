class Solution {
public:
    bool isPos(vector<int>& nums,int l){
        if(l<=1) return true;
        for(int i=0;i<=nums.size()-l;i++){
            int mask=0;
            bool isNice = true;
            for(int j=i;j<i+l;j++){
                if(mask&nums[j]){
                    isNice = false;
                    break;
                }
                mask|=nums[j];
            }
            if(isNice) return true;
        }
        return false;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,h=nums.size();
        int res=1;
        while(l<=h){
            int m=(l+h)/2;
            if(isPos(nums,m)){
                res=m;
                l=m+1;
            }
            else h=m-1;
        }
        return res;
    }
};