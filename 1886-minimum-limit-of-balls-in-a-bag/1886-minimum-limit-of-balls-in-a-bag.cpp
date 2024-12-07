class Solution {
public:
    bool ispos(vector<int>& nums,int m, int mx){
        int c=0;
        for(auto&i:nums){
            c+=i/m-(i%m==0);
            if(c>mx) return false;
        }
        return c<=mx;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=*max_element(begin(nums),end(nums)),ans=-1;
        while(l<=r){
            int m = (l+r)/2;
            if(ispos(nums,m,maxOperations)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return l;
    }
};