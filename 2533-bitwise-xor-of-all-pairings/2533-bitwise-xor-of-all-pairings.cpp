class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr=0,n1=nums1.size(),n2=nums2.size();
        if(n1%2==0 && n2%2==0) return 0;
        if(n1%2)
            for(auto&i:nums2)xr^=i;
        if(n2%2)
            for(auto&i:nums1)xr^=i;
        return xr;
    }
};