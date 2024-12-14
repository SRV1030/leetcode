class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l=0,r=0,n=nums.size(),mn=nums[r],mx=nums[r];
        long long w=0,t=0;
        for(r=0;r<n;++r){
            mn=min(mn,nums[r]);
            mx=max(mx,nums[r]);
            if(mx-mn>2){
                w=r-l;
                t+=(w*(w+1))/2;
                mn=mx=nums[r];
                l=r;
                while(l>0 && abs(nums[r]-nums[l-1])<=2){
                    --l;
                    mn=min(mn,nums[l]);
                    mx=max(mx,nums[l]);
                }
                if(l<r){
                    w=r-l;
                    t-=(w*(w+1))/2;
                }
            }
        }
        w=r-l;
        t+=(w*(w+1))/2;
        return t;
    }
};