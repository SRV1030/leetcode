class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0, size1 = nums1.size(), size2 = nums2.size();
        int mx = 0;
        while(i1 < size1 && i2 < size2){
            if(nums1[i1] <= nums2[i2]){
                mx = max(mx, i2 - i1);
                ++i2;
            }
            else
                ++i1;
            if(i2 < i1) 
                i2 = i1;
        }
        return mx;
    }
};