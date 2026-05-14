class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if(size1 > size2)
            return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = size1;
        while(left <= right){
            int part1 = (left + right) / 2;
            int part2 = (size1 + size2 + 1) / 2 - part1;
            int leftMax1 =  part1 == 0 ? INT_MIN : nums1[part1 - 1];
            int leftMax2 =  part2 == 0 ? INT_MIN : nums2[part2 - 1];
            int rightMin1 =  part1 == size1 ? INT_MAX : nums1[part1];
            int rightMin2 =  part2 == size2 ? INT_MAX : nums2[part2];
            if(leftMax1 <= rightMin2 && leftMax2 <= rightMin1){
                return (size1 + size2) % 2 ? max(leftMax1, leftMax2) : (double) (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
            }
            else if(leftMax1 > rightMin2)
                right = part1 - 1;
            else 
                left = part1 + 1;
        }
        return 0.0;
    }
};