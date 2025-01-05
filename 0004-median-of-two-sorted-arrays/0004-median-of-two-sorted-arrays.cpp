class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2)findMedianSortedArrays(nums2,nums1);
        int nt=n1+n2;
        int md=(nt+1)/2;
        int s=max(0,md-n2),e=min(n1,md); 
        while(s<=e){
            int m1=(s+e)/2,m2=md-m1;
            int l1=(m1-1>=0)?nums1[m1-1]:INT_MIN;
            int l2=(m2-1>=0)?nums2[m2-1]:INT_MIN;
            int r1=(m1<n1)?nums1[m1]:INT_MAX;
            int r2=(m2<n2)?nums2[m2]:INT_MAX;
            if(l1<=r2 && l2<=r1){
                if(nt%2)return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1>r2)e=m1-1;
            else s=m1+1;
        }
        return 0;
    }
};